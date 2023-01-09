int solve(Node *root, int &sum)
{
    if (!root)
        return 0;

    int ls = max(0, solve(root->left, sum));
    int rs = max(0, solve(root->right, sum));

    sum = max(sum, root->data + ls + rs);

    return max(ls, rs) + root->data;
}
int findMaxSum(Node *root)
{

    int sum = INT_MIN;

    solve(root, sum);

    return sum;
}