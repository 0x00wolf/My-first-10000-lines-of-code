    // looping through height 0 to -1
    RGBTRIPLE array[width];
    for (int i = 0, j = height; i < j; i++)
    {
        // looping through each row
        // copy items into a new temp array
        // set values of items in the original array to the reverse order of the temp array
        // I am blanking.
        for (int cc = width - 1, bb = 0; cc > bb; cc--)
        {
            for (int dd = 0, ee = width; dd < ee; dd++)
            {
                image[i][cc] = array[dd];
            }
        }
        for (int ccc = 0, bbb = width; ccc < bbb; ccc++)
        {
            image[i][ccc] = array[ccc];
        }
    }