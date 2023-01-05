void inOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    inOrder(root->left);
    ans.push_back(root->data);
    inOrder(root->right);
}