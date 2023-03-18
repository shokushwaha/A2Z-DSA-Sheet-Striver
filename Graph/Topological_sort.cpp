void dfs(int node, vector<int> adj[], vector<int> &visited, stack<int> &s)
{
    visited[node] = 1;
    for (auto i : adj[node])
    {
        if (!visited[i])
        {
            dfs(i, adj, visited, s);
        }
    }
    s.push(node);
}
vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> visited(V);
    stack<int> s;
    for (int i = 0; i < V; i++)
    {
        if (!visited[i])
            dfs(i, adj, visited, s);
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// do the normal dfs and while returning push the node in stack