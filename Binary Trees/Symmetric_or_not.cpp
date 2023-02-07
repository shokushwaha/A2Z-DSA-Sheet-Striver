bool check(struct Node *a, struct Node *b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    bool x = (a->data == b->data);
    bool y = check(a->left, b->right);
    bool z = check(a->right, b->left);

    return x && y && z;
}
bool isSymmetric(struct Node *root)
{
    if (!root)
        return true;
    return check(root->left, root->right);
}