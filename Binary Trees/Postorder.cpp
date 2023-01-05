void postOrder(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;

    postOrder(root->left);
    postOrder(root->right);
    ans.push_back(root->data);
}