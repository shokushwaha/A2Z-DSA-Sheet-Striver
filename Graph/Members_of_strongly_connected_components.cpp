void dfs(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    vis[node] = 1;
    for (auto it : adj[node])
    {
        if (!vis[it])
        {
            dfs(it, vis, adj, st);
        }
    }
    st.push(node);
}

void dfs2(int node, vector<int> &vis, vector<int> adjT[], vector<int> &temp)
{
    vis[node] = 1;
    temp.push_back(node);
    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs2(it, vis, adjT, temp);
        }
    }
}

vector<vector<int>> tarjans(int n, vector<int> adj[])
{
    // sort acc to finish time
    stack<int> st;
    vector<int> vis(n, 0);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // to reverse(transpose) the graph
    vector<int> adjT[n];
    for (int i = 0; i < n; i++)
    {
        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // reuse this visited array
    for (int i = 0; i < n; i++)
        vis[i] = 0;

    // as stack containing sorted nodes, So do dfs on it
    vector<vector<int>> ans;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();

        if (!vis[node])
        {
            vector<int> temp;
            dfs2(node, vis, adjT, temp); // dfs call
            sort(temp.begin(), temp.end());
            ans.push_back(temp);
        }
    }
    sort(ans.begin(), ans.end());
    return ans;
}