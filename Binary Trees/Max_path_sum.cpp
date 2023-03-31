int solve(Node *root, int &sum)
{
    if (!root)
        return 0;

    // if the left subtree is giving negative sum then do not consider path below the current
    int ls = max(0, solve(root->left, sum));

    // if the right subtree is giving negative sum then do not consider path below the current
    int rs = max(0, solve(root->right, sum));

    // storing the maximum sum
    sum = max(sum, root->data + ls + rs);

    return max(ls, rs) + root->data;
}
int findMaxSum(Node *root)
{

    int sum = INT_MIN;

    solve(root, sum);

    return sum;
}