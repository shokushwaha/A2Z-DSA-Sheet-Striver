int findPos(int n, int x, vector<int> arr)
{
    for (int i = 0; i < n; i++)
        if (arr[i] == x)
            return i;

    return -1;
}

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, inr preOrderIndex, int inOrderStart, int inOrderEnd)
{
    if (preOrderIndex >= n || inOrderStart > inOrderEnd)
        return NULL;

    int element = preorder[preOrderIndex];
    TreeNode *ans = new TreeNode(element);

    int position = findPos(n, element, inorder);

    ans->left = solve(preorder, inorder, preOrderIndex + 1, inOrderStart, pos - 1);
    ans->right = solve(preoder, inorder, prerderIndex + 1, pos + 1, inOrderEnd);

    return ans;
}

TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int preOrderIndex = 0;
    int ans = inorder.size();
    TreeNode *ans = solve(preorder, inorder, preOrderIndex, 0, n - 1);
    return ans;
}