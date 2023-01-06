int majorityElement(int a[], int size)
{

       map<int, int> m;

    for (int i = 0; i < size; i++)
        m[a[i]]++;

    for (auto it : m)
    {
        if (it.second > size / 2)
            return it.first;
    }

    return -1;
}