int bellmenFord(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    // m are the total number of edges
    vector<int> dist(n, 1e9);

    // setting distance of source as 0
    dist[src] = 0;

    // running the loop n-1 times
    for (int i = 1; i < n; i++)
    {
        // traverse all edges
        for (int j = 0; j < m; i++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];

            if (dist[u] != 1e9 && dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    // check for negative cycle
    bool flag = false;
    for (int i = 0; i < m; i++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];

        if (dist[u] + wt < dist[v])
            flag = true;
    }

    if (!flag)
        return dist[dest];

    return -1;
}