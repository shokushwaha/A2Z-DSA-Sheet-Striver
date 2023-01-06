vector<int> spiral(vector<vector<int>> &a, int n, int m)
{
    vector<int> ans;

    int count = 0;

    int total = n * m;

    int startingRow = 0;

    int startingCol = 0;

    int endingRow = n - 1;

    int endingCol = m - 1;

    while (count < total)
    {

        for (int index = startingCol; index <= endingCol; index++)
        {

            ans.push_back(a[startingRow][index]);

            count++;
        }

        startingRow++;

        for (int index = startingRow; index <= endingRow; index++)
        {

            ans.push_back(a[index][endingCol]);

            count++;
        }

        endingCol--;

        for (int index = endingCol; index >= startingCol; index--)
        {

            ans.push_back(a[endingRow][index]);

            count++;
        }

        endingRow--;

        for (int index = endingRow; index >= startingRow; index--)
        {

            ans.push_back(a[index][startingCol]);

            count++;
        }

        startingCol++;
    }
    return ans;
}