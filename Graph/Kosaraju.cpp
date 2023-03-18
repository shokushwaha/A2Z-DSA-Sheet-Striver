
void dfs(int node, vector<int> &vis, vector<vector<int>> adj, stack<int> &st)
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
void dfs3(int node, vector<int> &vis, vector<int> adjT[])
{
    vis[node] = 1;

    for (auto it : adjT[node])
    {
        if (!vis[it])
        {
            dfs3(it, vis, adjT);
        }
    }
}

int kosaraju(int V, vector<vector<int>> &adj)
{
    // storing the dfs edges according to finish time in stack....finishes first will be stored at last
    vector<int> vis(V, 0);
    stack<int> st;
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            dfs(i, vis, adj, st);
        }
    }

    // reversing the graph   a->b == b->a
    vector<int> adjT[V];
    for (int i = 0; i < V; i++)
    {
        vis[i] = 0;

        for (auto it : adj[i])
        {
            adjT[it].push_back(i);
        }
    }

    // counting the strongly connected components
    int scc = 0;
    while (!st.empty())
    {
        int node = st.top();
        st.pop();
        if (!vis[node])
        {

            dfs3(node, vis, adjT);
            scc++;
        }
    }

    return scc;
}

// start with the topological sort of the edges of the graph and store it in the stack.Then reverse all the directions in the graph and then while stack becomes empty,pop out the top element and do dfs on it and count total number of strongly connected components