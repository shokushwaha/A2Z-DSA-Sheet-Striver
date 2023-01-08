set<int> s;
int isPairPresent(struct Node *root, int target)
{
    if (root == NULL)
        return 0;

    if (isPairPresent(root->left, target))
        return 1;

    s.insert(target - root->data);

    if (s.find(root->data) != s.end())
        return 1;

    if (isPairPresent(root->right, target))
        return 1;

    return 0;
}