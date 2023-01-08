bool bst(Node *root, int mini, int maxi)
{
    if (root == NULL)
        return true;

    if (root->data > maxi || root->data < mini)
        return false;

    bool left = bst(root->left, mini, root->data);
    bool right = bst(root->right, root->data, maxi);

    return left && right;
}
bool isBST(Node *root)
{
    return bst(root, INT_MIN, INT_MAX);
}