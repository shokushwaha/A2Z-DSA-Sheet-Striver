bool isIdentical(Node *r1, Node *r2)
{
    if (r1 == NULL && r2 == NULL)
        return true;

    if (r1 == NULL || r2 == NULL)
        return false;

    bool a = r1->data == r2->data, b = isIdentical(r1->left, r2->left), c = isIdentical(r1->right, r2->right);
    return a && b && c;
}