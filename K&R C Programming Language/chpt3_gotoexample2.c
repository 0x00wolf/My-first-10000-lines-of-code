    for (i = 0; i < n; i++)
        for (j = 0; j < m; j++)
            if (a[i] == b[j])
                goto found;
    // didn't find any common element
    ...
found:
    // got one: a[i] == b[j]
    ...
