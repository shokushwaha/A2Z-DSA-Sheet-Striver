bool solve(vector<int> &ans, TreeNode *root, int dest)
{
    if (!root)
        return false;

    ans.push_back(root->data);

    if (root->data == dest)
        return true;

    if (solve(ans, root->left, dest) || solve(ans, root->right, dest))
        return true;

    ans.pop_back();

    return false;
}
vector<int> path(TreeNode *root, int dest)
{
    vector<int> ans;

    solve(ans, root, dest);

    return ans;
}