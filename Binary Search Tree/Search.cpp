bool search(Node *root, int x)
{

    while (root)
    {
        if (root->data == x)
            return true;

        else if (root->data > x)
            root = root->left;
        else if (root->data < x)
            root = root->right;
    }

    return false;
}
