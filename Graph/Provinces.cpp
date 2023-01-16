void dfs(vector<int> adjL[], int node, int vis[])
{
    vis[node] = 1;
    for (auto it : adjL[node])
    {
        if (!vis[it])
            dfs(adjL, it, vis);
    }
}
int numProvinces(vector<vector<int>> adj, int V)
{
    vector<int> adjL[V];
    for (int i = 0; i < V; i++)
    {
        for (int j = 0; j < V; j++)
        {
            if (adj[i][j] == 1 && i != j)
            {
                adjL[i].push_back(j);
                adjL[j].push_back(i);
            }
        }
    }
    int vis[V] = {0};
    int cnt = 0;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            cnt++;
            dfs(adjL, i, vis);
        }
    }

    return cnt;
}