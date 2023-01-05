void preOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    ans.push_back(root->data);
    preOrder(root->left);
    preOrder(root->right);
}