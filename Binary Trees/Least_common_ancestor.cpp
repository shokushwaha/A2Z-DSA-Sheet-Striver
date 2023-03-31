void solve(TreeNode *root, TreeNode *a, TreeNode *b)
{
    if (root == NULL || root == a || root == b)
        return root;

    TreeNode *left = solve(root->left, a, b);
    TreeNode *right = solve(root->right, a, b);

    if (left == NULL)
        return right;
    else if (right == NULL)
        return left;
    else
        return root;
}

TreeNode *lca(TreeNode *root, TreeNode *a, TreeNode *b)
{
    return solve(root, a, b);
}