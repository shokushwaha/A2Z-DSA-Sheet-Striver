vector<int> findSpiral(Node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;

    queue<Node *> q;

    q.push(root);

    bool leftToRight = false;
    while (!q.empty())
    {
        auto x = q.size();
        vector<int> temp(x);

        for (int i = 0; i < x; i++)
        {
            Node *y = q.front();
            q.pop();
            int index = leftToRight ? i : x - i - 1;

            temp[index] = y->data;

            if (y->left)
                q.push(y->left);

            if (y->right)
                q.push(y->right);
        }
        leftToRight = !leftToRight;
        for (auto it : temp)
        {
            ans.push_back(it);
        }
    }
    return ans;
}