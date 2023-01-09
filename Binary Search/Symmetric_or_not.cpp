bool check(struct Node *a, struct Node *b)
{
    if (a == NULL && b == NULL)
        return true;

    if (a == NULL || b == NULL)
        return false;

    return (a->data == b->data) && check(a->left, b->right) && check(a->right, b->left);
}
bool isSymmetric(struct Node *root)
{

    if (!root)
        return true;
    return check(root->left, root->right);
}