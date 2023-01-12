vector<int> count_NGE(int n, vector<int> &arr, int queries, vector<int> &indices)
{

    vector<int> res;

    for (int i = 0; i < queries; i++)
    {

        int count = 0;

        for (int j = indices[i] + 1; j < n; j++)
        {

            if (arr[j] > arr[indices[i]])

                count++;
        }

        res.push_back(count);
    }

    return res;
}
