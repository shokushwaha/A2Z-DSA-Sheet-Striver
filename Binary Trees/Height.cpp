int solve(TreeNode *root)
{
    if (root == NULL)
        return 0;

    return max(solve(root->left), solve(root->right)) + 1;
}
void height(TreeNode *root)
{
    int x = solve(root);
}