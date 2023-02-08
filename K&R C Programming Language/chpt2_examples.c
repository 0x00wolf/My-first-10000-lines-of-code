/* for the following: a newline is printed after every tenth element and after
 * every n-th. All other elements are followed by one blank. */
for (i = 0; i < n; i ++)
    printf("%6d%c", a[i], (i%10==9 || i == n-1) ? '\n' : ' ');

// another example
pritnf("You have %d item%s.\n", n , n==1 ? "" : "s");
