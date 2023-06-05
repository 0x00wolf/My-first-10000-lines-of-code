#define _GNU_SOURCE // Needed by syscall
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h> // Stat systemcall

#include <sys/syscall.h>

#define BUF_SIZE 1024

#define MFW_EXIT(s) do {perror (s); exit (EXIT_FAILURE);} while (0)

// Dirent Data struct
struct linux_dirent {
    long            d_ino;
    off_t           d_off;
    unsigned short  d_reclen;
    char            d_name[];
};

char folder[1024];

// getdent wrapper. *Not provided by glibc
int getdents(int fd, char *buf, int len)
{ return syscall (SYS_getdents, fd, buf, len); }

typedef int (*PAYLOAD_FUNC)(char *);

int payload (char *target) {
    printf ("Doing malware things to %s\n", target);
}

int select_target  (PAYLOAD_FUNC pf) {
    char buf[BUF_SIZE];
    struct linux_dirent *de;
    struct stat st;
    int fd, n, i;

    // Open directory using open
    if ((fd = open (folder, O_RDONLY | O_DIRECTORY)) < 0) MFW_EXIT("open: ");

    while (1) {
        n = getdents (fd, buf, BUF_SIZE);
        if (n < 0) MFW_EXIT ("getdents:");
        if (n == 0) break;

        // Build file name
        for (i = 0; i < n;) {
            de = (struct linux_dirent *)(buf + i);        
            
            if ((fstatat (fs, de->d_name, &st)) < 0) {
                perror ("stat:");
                continue; // Just ignore the error
            }
            if (((st.st_mode & S_IFMT) == S_IFREG)
                && (st.st_mode & 00111))
                pf (target);
            i += de->d_reclen;
        }
        // Read directory entries
    }
done:
    close (fd);
    return 0;
}

int main (int argc, char *argv[]) {
    strcpy (folder, argv[1]);
    while (select_target(payload));
}
