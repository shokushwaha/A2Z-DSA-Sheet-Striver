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
            int adjNode = it[0];
            int edgeWght = it[1];

            if (dist + edgeWght < dis[adjNode])
            {
                dis[adjNode] = dist + edgeWght;

                pq.push({dis[adjNode], adjNode});
            }
        }
    }
    return dis;
}

// make a min heap and a distance array initialized with infinity in staring.Priority queue should be in the form of pair of{disc,node}.While the queue is not empty pop out the top element.Then do the relaxation on adjacent node ie dis[adjNode]+dis<dis[adjNode] on every node and if the relaxation is true push the result in the min heap