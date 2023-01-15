vector<int> verticalOrder(Node *root)
{
    queue<pair<int, Node *>> q;
    q.push({0, root});
    map<int, vector<int>> m;

    while (!q.empty())
    {
        auto temp = q.front();
        q.pop();

        int hd = temp.first;
        Node *curr = temp.second;

        m[hd].push_back(curr->data);
        if (curr->left)
            q.push({hd - 1, curr->left});
        if (curr->right)
            q.push({hd + 1, curr->right});
    }

    vector<int> ans;
    for (auto it : m)
        for (auto jt : it.second)
            ans.push_back(jt);

    return ans;
}