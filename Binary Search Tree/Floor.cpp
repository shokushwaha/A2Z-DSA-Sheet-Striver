int floor(Node *root, int x)
{

    if (root == NULL)
        return -1;
    int ans = -1;
    while (root)
    {
        if (root->data <= x)
        {
            ans = root->data;
            root = root->right;
        }
        else
            root = root->left;
    }

    return ans;
}
