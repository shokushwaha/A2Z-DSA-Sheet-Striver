void majorityElement(int a[], int size)
{

    map<int, int> m;
    int once = -1, twice = -1;
    for (int i = 0; i < size; i++)
        m[a[i]]++;

    for (auto it : m)
    {
        if (it.second == 1)
            once = it.first;
        if (it.second == 2)
            twice = it.first;
    }
}