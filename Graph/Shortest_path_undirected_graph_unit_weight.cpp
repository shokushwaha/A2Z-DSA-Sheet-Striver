
vector<int> shortestPath(vector<int> adj[], int src, int V, int dest)
{
    vector<int> ans;
    stack<int> s;
    int vis[V] = {0};
    int parent{v} = {0};
    queue<int> q;

    q.push(src);
    parent[src] = -1;
    vis[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto it : adj[front])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                parent[it] = front;
                q.push(it);
            }
        }
    }

    int currNode = dest;
    ans.push_back(currNode);
    while (currNode != src)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}