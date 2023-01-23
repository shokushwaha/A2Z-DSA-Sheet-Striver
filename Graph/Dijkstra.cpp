vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> distance(V);
    for (int i = 0; i < V; i++)
    {

        distance[i] = INT_MAX;
    }
    distance[S] = 0;
    st.insert(make_pair(0, S));
    while (!st.empty())
    {
        pair<int, int> top = *(st.begin());
        int distanceofnode = top.first;
        int node = top.second;
        st.erase(st.begin());

        for (auto neighbour : adj[node])
        {
            if (distanceofnode + neighbour[1] < distance[neighbour[0]])
            {
                auto record = st.find(make_pair(distance[neighbour[0]], neighbour[0]));
                if (record != st.end())
                {
                    st.erase(record);
                }
                // distance update...
                distance[neighbour[0]] = distanceofnode + neighbour[1];

                // inserting record in set..
                st.insert(make_pair(distance[neighbour[0]], neighbour[0]));
            }
        }
    }
    return distance;
}