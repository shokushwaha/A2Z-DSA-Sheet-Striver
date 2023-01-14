void solve(Node *root, vector<int> &ans, int level)
{

    if (!root)
        return;

    if (ans.size() == level)
        ans.push_back(root->data);

    solve(root->right, ans, level++);
    solve(root->left, ans, level++);
}
vector<int> rightView(Node *root)
{

    vector<int> ans;

    solve(root, ans, 0);

    return ans;
}