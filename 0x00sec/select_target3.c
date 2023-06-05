#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>   // Stat struct

#define BUF_SIZE 1024

// XXX: Move this to a .h file
// Dirent Data Structure
struct linux_dirent {
    long    d_ino;
    long    d_off;
    unsigned short d_reclen;
    char    d_name[];
};

int mfw_getdents (int fd, char *buf, int len);
int mfw_exit (int r);
int mfw_openat (int dirfd, const char *pathname, int flags);
int mfw_newstatat (int dirfd, char *p, struct stat *st, int flags);
int mfw_close (int fd);
size_t mfw_write (int fd, const void *buf, size_t count);

#define MFW_EXIT(s) do {mfw_exit (1);} while (0)

typedef int (*PAYLOAD_FUNC)(char *);

// Global vars
int level = 0;
char tabs[1024];

int mfw_puts (char *s) {
    while (*s) mfw_write (1, s++, 1);
}

// Helper function to write tabbed strings
int mfw_print_tstr  (char *s, char *v) {
    mfw_puts (tabs);
    mfw_puts (s);
    if (v) mfw_puts (v);
    mfw_puts ("\n");
}

int payload (char *target) {
    mfw_print_tstr ("  ++ Doing malware things to ", target);
}

int select_target (int old_fd, char *folder, PAYLOAD_FUNC pf) {
    char                buf[BUF_SIZE];
    struct linux_dirent *de;
    struct stat         st;
    int                 fd, n, i;

    tabs[level] = ' ';
    level ++;

    mfw_print_tstr (">> Entering ", folder);

    if ((fd = mfw_openat (old_fd, folder, O_RDONLY | O_DIRECTORY)) < 0) goto clean;

    while (1) {
        n = mfw_getdents (fd, buf, BUF_SIZE);
        if (n < 0) continue; // Silently ignore errors
        if (n == 0) break;

        for (i = 0; i < n;) {
            de = (struct linux_dirent *)(buf + i);
            if ((mfw_newstatat (fd, de->d_name, &st, 0)) < 0) goto next;

            if (((st.st_mode & S_IFMT) == S_IFREG) && (st.st_mode & 00111))
                pf (de->d_name);
            else if (((st.st_mode & S_IFMT) == S_IFDIR)
                    && !(de->d_name[0] == '.'
                        && (de->d_name[1] == 0
                            || (de->d_name[1] == '.' && de->d_name[2] == 0))))
                select_target (fd, de->d_name, pf);
        next:
            i += de->d_reclen;
        }
    }
    clean:
        mfw_print_tstr ("<< Leaving ", folder);
        tabs[level] = 0;
        level--;
        mfw_close (fd);
        return 0;
}

int main (int argc, char *argv[]) {
    for (int i = 0; i <1024; tabs[i++] = 0);
    while (select_target(0, argv[1], payload));
}
