Node *lca(Node *root, int n1, int n2)
{
    // base case
    if (root == NULL)
        return NULL;

    // if any node matches the n1 or n2 return that node
    if (root->data == n1 || root->data == n2)
        return root;

    // recursive calls
    Node *leftAns = lca(root->left, n1, n2);
    Node *rightAns = lca(root->right, n1, n2);

    if (leftAns && rightAns)
        return root;

    else if (leftAns && rightAns == NULL)
        return leftAns;

    else if (rightAns && leftAns == NULL)
        return rightAns;

    else
        return NULL;
}