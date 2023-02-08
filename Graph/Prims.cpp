int spanningTree(int V, vector<vector<int>> adj[])
{
    // priotity queue storing pair in the form of {weight,node} in min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // visited array to keep track of all the visited nodes
    vector<int> vis(V);

    // pushing root in min heap
    pq.push({0, 0});

    vector<vector<int>> mst;

    int sum = 0;

    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        int wght = top.first;
        int node = top.second;

        if (vis[node])
            continue;

        vis[node] = 1;
        sum += wght;

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWght = it[1];

            if (!vis[adjNode])
                pq.push({edgeWght, adjNode});
        }
    }
    return sum;
}