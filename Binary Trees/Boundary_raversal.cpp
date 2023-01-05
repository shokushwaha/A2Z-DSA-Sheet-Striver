void leftSubTree(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    ans.push_back(root->data);
    if (root->left)
        leftSubTree(root->left, ans);
    else
        leftSubTree(root->right, ans);
}

void leaf(Node *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }

    leaf(root->left, ans);
    leaf(root->right, ans);
}
void rightSubTree(Node *root, vector<int> &ans)
{
    if (root == NULL || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        rightSubTree(root->right, ans);
    else
        rightSubTree(root->left, ans);
    ans.push_back(root->data);
}

vector<int> boundary(Node *root)
{

    vector<int> ans;
    if (root == NULL)
        return ans;

    ans.push_back(root->data);

    leftSubTree(root->left, ans);

    leaf(root->left, ans);
    leaf(root->right, ans);

    rightSubTree(root->right, ans);

    return ans;
}
