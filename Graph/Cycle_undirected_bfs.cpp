bool bfs(vector<int> adj[], int src, int vis[])
{
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push({src, -1});

    while (!q.empty())
    {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto i : adj[cur])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, cur});
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, i, vis) == true)
                return true;
        }
    }
    return false;
}