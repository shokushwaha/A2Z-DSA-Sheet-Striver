vector<int> levelOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        q.pop();
        if (temp->left)
            q.push(temp->left);
        if (temp->right)
            q.push(temp->right);
        ans.push_back(temp->data);
    }

    return ans;
}