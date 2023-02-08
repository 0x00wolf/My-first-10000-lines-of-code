#define SIZE 1 << 25

int binsearch(int x, int v[], int n);

int values[SIZE];

int main(void)
{
    int i, n = SIZE;
    for (i = 0; i < n; i++)
        values[i] = i;
    // Search for every item
    for (i = 0; i < n; i++)
        binsearch(i, values, n);
    return 0;
}

int binsearch(int x, int v[], int n)
{
    int low, high, mid;

    low = 0;
    high = n - 1;
    while (low < high) {
        mid = (low + high) / 2;
        if (x > v[mid])
            low = mid + 1;
        else
            high = mid;
    }
    return (x == v[low] ? low: -1;
}
