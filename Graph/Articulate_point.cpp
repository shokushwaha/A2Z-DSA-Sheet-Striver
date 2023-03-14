int timer = 0;
void dfs(int node, int parent, vector<int> adj[], vector<int> &vis,
         int tin[], int low[], vector<int> &mark)
{

    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    int firstNodeChild = 0;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;

        if (!vis[it])
        {
            dfs(it, node, adj, vis, tin, low, mark);
            low[node] = min(low[node], low[it]);

            // articulate point - we can reach it in time greater than or equal to discovery time of the node
            if (low[it] >= tin[node] && parent != -1)
                mark[node] = 1;

            firstNodeChild++;
        }
        else
        {
            low[node] = min(low[node], tin[it]);
        }
    }
    if (firstNodeChild > 1 && parent == -1)
    {
        mark[node] = 1;
    }
}

vector<int> articulationPoints(int V, vector<int> adj[])
{
    vector<int> vis(V, 0);
    int tin[V];
    int low[V];
    vector<int> mark(V, 0);

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
            dfs(i, -1, adj, vis, tin, low, mark);
    }

    vector<int> ans;
    for (int i = 0; i < V; i++)
    {
        if (mark[i] == 1)
            ans.push_back(i);
    }

    if (ans.size() == 0)
        return {-1};
    return ans;
}
