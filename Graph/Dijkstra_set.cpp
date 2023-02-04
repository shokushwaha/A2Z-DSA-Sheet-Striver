vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> s;

    vector<int> dis(V, 1e9);

    dis[S] = 0;
    s.insert({0, S});

    while (!s.empty())
    {
        auto it = *(s.begin());
        int dist = it.first;
        int node = it.second;
        s.erase(it);

        for (auto it : adj[node])
        {
            int adjNode = it[0];
            int edgeWght = it[1];

            if (dist + edgeWght < dis[adjNode])
            {
                if (dis[adjNode] != 1e9)
                    s.erase({dis[adjNode], adjNode});

                dis[adjNode] = dist + edgeWght;

                s.insert({dis[adjNode], adjNode});
            }
        }
        return dis;
    }
}