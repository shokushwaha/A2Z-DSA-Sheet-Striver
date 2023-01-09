int solve(Node *root, int &ans)
{
    if (!root)
        return 0;

    int l = solve(root->left, ans);
    int r = solve(root->right, ans);

    ans = max(ans, l + r + 1);

    return 1 + max(l, r);
}
int diameter(Node *root)
{

    int ans = INT_MIN;

    solve(root, ans);
    return ans;
}