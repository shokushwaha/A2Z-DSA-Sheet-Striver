void topoSort(int src, int vis[], vector<pair<int, int>> adj, stack<int> &s)
{
    vis[src] = 1;

    for (auto it : adj[src])
    {
        if (!vis[it.first])
        {
            topoSort(it.first, vis, adj, s);
        }
    }
    s.push(src);
}
vector<int> shortestPath(vector<pair<int, int>> adj, int V)
{

    vector<int> topo;
    stack<int> s;
    int vis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            topoSort(i, vis, adj, s);
    }

    vector<int> dist;
    for (int i = 0; i < V; i++)
        dist[i] = 1e9;

    dist[0] = 0;

    while (!s.empty())
    {
        int node = st.top();
        st.pop();

        for (auto it : adj[node])
        {
            int curr = it.first;
            int wght = it.second;

            if (dist[node] + wght < dist[curr])
            {
                dist[curr] = dist[node] + wght;
            }
        }
    }

    return dist;
}