Node *insert(Node *root, int Key)
{
    if (root == NULL)
    {
        root = new Node(Key);
        return root;
    }

    if (Key < root->data)
        root->left = insert(root->left, Key);

    if (Key > root->data)
        root->right = insert(root->right, Key);

    return root;
}
