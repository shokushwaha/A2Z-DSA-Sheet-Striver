vector<int> dijkshtra(int V, vector<vector<int>> adj[], int src)
{
    priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> pq;

    vector<int> dis;

    for (int i = 0; i < V; i++)
        dis[i] = 1e9;

    dis[src] = 0;

    // storing pair in priority queue in the form of (distance,node)
    pq.push({0, src});

    while (!pq.empty())
    {
        int dist = pq.top().first;
        int node = pq.top().second;
        pq.pop();
        for (auto it : adj[node])
        {
            int edgeWght = it[1];
            int adjNode = it[0];

            if (dist + edgeWght < dis[adjNode])
                dis[adjNode] = dist + edgeWght;

            pq.push({dis[adjNode], adjNode});
        }
    }
    return dis;
}