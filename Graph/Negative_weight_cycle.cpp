
int isNegativeWeightCycle(int n, vector<vector<int>> edges)
{

    vector<int> dist(n, 1e8);
    dist[0] = 0;
    for (int i = 0; i < n; i++)
    {
        for (auto it : edges)
        {
            int u = it[0];
            int v = it[1];
            int wt = it[2];
            if (dist[u] + wt < dist[v])
                dist[v] = dist[u] + wt;
        }
    }

    for (auto it : edges)
    {
        int u = it[0];
        int v = it[1];
        int wt = it[2];
        if (dist[u] + wt < dist[v])
            return 1;
    }

    return 0;
}