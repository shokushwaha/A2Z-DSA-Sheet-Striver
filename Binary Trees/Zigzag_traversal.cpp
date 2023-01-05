vector<int> zigZagTraversal(Node *root)
{

    vector<int> result;

    if (root == NULL)
    {
        return result;
    }

    int count = 0;
    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {

        vector<int> ans;

        int n = q.size();

        for (int i = 0; i < n; i++)
        {
            Node *temp = q.front();
            q.pop();
            ans.push_back(temp->data);

            if (temp->left)
            {
                q.push(temp->left);
            }

            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        if (count % 2 != 0)
        {
            reverse(ans.begin(), ans.end());
        }
        count++;

        for (auto x : ans)
        {
            result.push_back(x);
        }
    }
    return result;
}
}
;