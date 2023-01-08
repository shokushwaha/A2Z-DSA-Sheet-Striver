void pred(Node *root, Node *&ans1, int key)
{
    if (!root)
        return;

    pred(root->left, ans1, key);
    if (root->key < key)
        ans1 = root;

    pred(root->right, ans1, key);
}
void succ(Node *root, Node *&ans2, int key)
{
    if (!root)
        return;

    succ(root->right, ans2, key);

    if (root->key > key)
        ans2 = root;

    succ(root->left, ans2, key);
}
void findPreSuc(Node *root, Node *&pre, Node *&suc, int key)
{
    pred(root, pre, key);
    succ(root, suc, key);
}