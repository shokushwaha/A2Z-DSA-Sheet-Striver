bool isCyclic(int V, vector<int> adj[])
{
    vector<int> indegree(V, 0);
    queue<int> q;
    for (int v = 0; v < V; v++)
    {
        for (int cur : adj[v])
        {
            indegree[cur]++;
        }
    }
    for (int v = 0; v < V; v++)
    {
        if (indegree[v] == 0)
            q.push(v);
    }
    int counter = 0;
    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        counter++;
        for (int v : adj[cur])
        {
            indegree[v]--;
            if (indegree[v] == 0)
                q.push(v);
        }
    }
    return (counter != V);
}

// kahn's algorithm gives linear ordering of n vertices but if there exists a cycle the algorithm will break in between and the size of topo array will not be equal to the total number of vertices