vector<int> preOrder(TreeNode *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<TreeNode *> q;

    q.push(root);

    while (!q.empty())
    {
        TreeNode *temp = q.front();
        ans.push_back(temp->data);
        q.pop();
        if (temp->right)
            q.push(temp->right);
        if (temp->left)
            q.push(temp->left);
    }

    return ans;
}