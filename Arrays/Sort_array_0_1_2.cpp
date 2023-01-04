void sortArr(int A[], int n)
{
    int z = 0, o = 0, t = 0;
    for (int i = 0; i < n; i++)
    {
        if (A[i] == 0)
            z++;
        if (A[i] == 1)
            o++;
        if (A[i] == 2)
            t++;
    }

    int cnt = 0;
    while (z != 0)
    {
        A[cnt] = 0;
        z--;
        cnt++;
    }
    while (o != 0)
    {
        A[cnt] = 1;
        o--;
        cnt++;
    }
    while (t != 0)
    {
        A[cnt] = 2;
        t--;
        cnt++;
    }
}