void solve(Node *root, int &ans)
{
    if (root == NULL)
        return;

    ans = min(ans, root->data);

    if (root->left)
        solve(root->left, ans);

    if (root->right)
        solve(root->right, ans);
}
int minValue(Node *root)
{

    if (root == NULL)
        return -1;
    int ans = INT_MAX;
    solve(root, ans);
    return ans;
}
