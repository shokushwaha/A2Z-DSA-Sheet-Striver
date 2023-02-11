void countAllNodes(struct Node *tree, int &x)
{
    if (tree == NULL)
        return;

    x++;
    countAllNodes(tree->left, x);
    countAllNodes(tree->right, x);
}
bool isCBT(struct Node *tree, int totalNodes, int index)
{
    if (tree == NULL)
        return true;

    if (index >= totalNodes)
        return false;

    return isCBT(tree->left, totalNodes, 2 * index + 1) && isCBT(tree->right, totalNodes, 2 * index + 2);
}
bool orderVal(struct Node *root)
{
    if (root == NULL)
        return true;
    if (root->left == NULL && root->right == NULL)
        return true;

    if (root->right == NULL)
        return root->data > root->left->data;

    else
        return (root->data > root->left->data && root->data > root->right->data && orderVal(root->left) && orderVal(root->right));
}
bool isHeap(struct Node *tree)
{

    int index = 0;
    int totalNodes = 0;
    countAllNodes(tree, totalNodes);
    if (isCBT(tree, totalNodes, index) && orderVal(tree))
        return true;

    else
        return false;
}