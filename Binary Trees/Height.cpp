int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;

    int left = solve(root->left);
    int right = solve(root->right);

    int ans = max(left, right) + 1;
    return ans;
}
void height(TreeNode *root)
{
    int x = solve(root);
}