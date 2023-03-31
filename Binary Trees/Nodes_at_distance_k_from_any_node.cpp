
queue<Node *> q;
unordered_map<Node *, Node *> parentTrack;
unordered_map<Node *, bool> visited;
Node *targetNode = NULL;

void parent(Node *root, int target)
{
    q.push(root);
    while (!q.empty())
    {
        root = q.front();
        q.pop();

        if (root->data == target)
            targetNode = root;

        if (root->left)
        {
            q.push(root->left);
            parentTrack[root->left] = root;
        }
        if (root->right)
        {
            q.push(root->right);
            parentTrack[root->right] = root;
        }
    }
}
vector<int> KDistanceNodes(Node *root, int target, int k)
{

    int curr_level = 0;

    parent(root, target);

    q.push(targetNode);

    while (!q.empty())
    {
        int n = q.size();

        if (k == curr_level)
            break;

        for (int i = 0; i < n; ++i)
        {
            Node *curr = q.front();
            q.pop();
            visited[curr] = true;

            if (curr->left && visited[curr->left] == false)
            {
                visited[curr->left] = true;
                q.push(curr->left);
            }
            if (curr->right && visited[curr->right] == false)
            {
                visited[curr->right] = true;
                q.push(curr->right);
            }
            if (parentTrack[curr] && visited[parentTrack[curr]] == false)
            {
                visited[parentTrack[curr]] == true;
                q.push(parentTrack[curr]);
            }
        }
        curr_level++;
    }

    vector<int> ans;

    while (!q.empty())
    {
        root = q.front();
        q.pop();
        ans.push_back(root->data);
    }

    sort(ans.begin(), ans.end());

    return ans;
}