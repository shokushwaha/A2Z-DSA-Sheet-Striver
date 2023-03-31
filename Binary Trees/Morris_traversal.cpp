void solve(Node *root, vector<int> &ans)
{

    Node *curr = root;
    Node *predecessor = NULL;
    while (curr != NULL)
    {
        if (curr->left == NULL)
        {
            ans.push_back(curr->data);
            curr = curr->right;
        }

        else
        {
            predecessor = curr->left;
            while (predecessor->right && predecessor->right != curr)
                predecessor = predecessor->right;

            if (predecessor->right == NULL)
            {
                predecessor->right = curr;
                curr = curr->left;
            }
            else
            {
                predecessor->right = NULL;
                ans.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}
vector<int> inOrder(Node *root)
{
    vector<int> ans;
    solve(root, ans);
    return ans;
}