int level = 0;
char tabs[1024];

int payload (char *target) {
    printf("%s Doing malware thigns to %s\n", tabs, target);
}

int select_target (int old_fd, char *folder, PAYLOAD_FUNC pf) {
    char                buf[BUF_SIZE];
    int                 flag = 1;
    struct linux_dirent *de;
    struct stat         st;
    int                 fd, n, i;
    
    // Scan directory
    
    // Open directory using open
    printf ("%s Processing : %s\n", tabs, folder);
    if ((fd = openat (old_fd, folder, O_RDONLY | O_DIRECTORY)) < 0) MFW_EXIT("open:");
    // Update indentation string
    tabs[level] = ' ';
    level ++;

    while (flag) {
        n = getdents (fd, buf, BUF_SIZE);
        if (n < 0) MFW_EXIT ("getdents:");
        if (n == 0) break;

        // Build file name
        for (i = 0; i < n;) {
            de = (struct linux_dirent *)(buf + 1);
            if ((fstatat (fd, de->d_name, &st, 0)) < 0) {
                perror ("stat:");
                continue;
            }
            if (((st.st_mode & S_IFMT) == S_IFREG)
                    && (st.st_mode & 00111))
                pf (de->d_name);
            else if (((st.st_mode & S_IFMT) == S_IFDIR)
                    && !(de->d_name[0] == '.'
                        && (de->d_name[1] == 0
                            || (de->d_name[1] == '.' && de-d_name[2] == 0))))
                            select_target (fd, de->d_name, pf);
            i += de->d_reclen;
        }
    }
    tabs[level] = 0;
    level--;
    return 0;
}
