void solve(Node *root, int k, int &count, vector<int> &temp)
{
    if (!root)
        return;

    temp.push_back(root->data);

    solve(root->left, k, count, temp);
    solve(root->right, k, count, temp);

    int sum = 0;

    for (int i = temp.size() - 1; i >= 0; i--)
    {
        sum += temp[i];
        if (sum == k)
            count++;
    }

    temp.pop_back();
}

int sumK(Node *root, int k)

{
    vector<int> temp;
    int count = 0;
    solve(root, k, count, temp);
    return count;
}