bool dfs(int node, int vis[], vector<int> adj[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, pathVis) == true)
                return true;
        }
        else if (pathVis[i] == 1)
            return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0}, pathVis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, pathVis))
                return true;
        }
    }
    return false;
    }