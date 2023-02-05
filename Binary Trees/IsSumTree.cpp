pair<bool, int> isSumTreeFast(Node *root)
{
    // base case
    if (root == NULL)
    {
        pair<bool, int> p = make_pair(true, 0);
        return p;
    }

    // leaf node
    if (root->left == NULL && root->right == NULL)
    {
        pair<bool, int> p = make_pair(true, root->data);
        return p;
    }

    // calling the function for left part
    pair<bool, int> leftAns = isSumTreeFast(root->left);
    // calling the function for right part
    pair<bool, int> rightAns = isSumTreeFast(root->right);

    // left subtree is sumtree or not
    bool isLeftSumTree = leftAns.first;
    // right subtree is sumtree or not
    bool isRightSumTree = rightAns.first;

    // left subtree sum
    int leftSum = leftAns.second;
    // right subtree sum
    int rightSum = rightAns.second;

    // checking the condition for the sum tree
    bool cond = root->data == leftSum + rightSum;

    pair<bool, int> ans;

    // if the left and right subtrees are sumtree and the root is equal to the sum of left and right subtree then the answer is true
    if (isLeftSumTree && isRightSumTree && cond)
    {
        ans.first = true;
        ans.second = 2 * root->data;
    }
    else
    {
        ans.first = false;
        ans.second = -1;
    }

    return ans;
}
bool isSumTree(Node *root)
{
    return isSumTreeFast(root).first;
}