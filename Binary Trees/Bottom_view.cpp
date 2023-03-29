vector<int> bottomView(Node *root)
{

    // map : hd -> node
    map<int, int> mp;

    // node -> hd
    queue<pair<Node *, int>> q;
    q.push({root, 0});
    vector<int> ans;
    while (q.empty() == false)
    {
        auto curr = q.front();
        q.pop();

        mp[curr.second] = curr.first->data;
        if (curr.first->left != NULL)
        {
            q.push({curr.first->left, curr.second - 1});
        }
        if (curr.first->right != NULL)
        {
            q.push({curr.first->right, curr.second + 1});
        }
    }
    for (auto &e : mp)
    {
        ans.push_back(e.second);
    }
    return ans;
}