void solve(Node *root)
{
    if (!root)
        return;

    solve(root->left);
    solve(root->right);

    Node *temp = root->left;
    root->left = root->right;
    root->right = temp;
}
void mirror(Node *node)
{
    solve(node);
}