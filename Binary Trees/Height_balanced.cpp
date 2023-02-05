pair<bool, int> isBalancedFast(Node *root)
{
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }
    pair<bool, int> left = isBalancedFast(root->left);
    pair<bool, int> right = isBalancedFast(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;

    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;

    if (leftAns && rightAns && diff)
        ans.first = true;

    else
        ans.first = false;

    return ans;
}
bool isBalanced(Node *root)
{
    return isBalancedFast(root).first;
}