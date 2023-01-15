int heightLeft(Node *root)
{
    int cnt = 0;
    while (root)
    {
        cnt++;
        root = root->left;
    }
    return cnt;
}
int heightRight(Node *root)
{
    int cnt = 0;
    while (root)
    {
        cnt++;
        root = root->right;
    }
    return cnt;
}
int countNodes(Node *root)
{
    if (root == NULL)
        return 0;

    int lh = heightLeft(root);
    int rh = heightRight(root);
    if (lh == rh)
        return ((1 << lh) - 1);
    else
        return 1 + countNodes(root->left) + countNodes(root->right);
}