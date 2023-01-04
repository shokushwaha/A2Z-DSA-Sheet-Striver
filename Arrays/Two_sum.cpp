bool twoSum(vector<int> arr, int x)
{
    sort(arr.begin(), arr.end());

    int i = 0, j = arr.size() - 1;
    while (i < j)
    {
        if (arr[i] + arr[j] == x)
            return true;
        else if (arr[i] = arr[j] < x)
            i++;
        else
            j--;
    }
    return false;
}