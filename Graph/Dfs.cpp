void dfs(int node, vector<int> &ans, vector<int> adj[], int vis[])
{
    vis[node] = 1;
    ans.push_back(node);

    for (auto it : adj[node])
    {
        if (!vis[it])
            dfs(it, ans, adj, vis);
    }
}
vector<int> dfsOfGraph(int V, vector<int> adj[])
{

    vector<int> ans;
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (vis[i] == 0)
            dfs(i, ans, adj, vis);
    }
    return ans;
}