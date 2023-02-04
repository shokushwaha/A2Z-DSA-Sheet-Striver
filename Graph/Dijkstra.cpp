vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
{
    set<pair<int, int>> st;
    vector<int> distance(V);

    // initialsing all distances with large value
    for (int i = 0; i < V; i++)
        distance[i] = INT_MAX;

    // setting distance of source as 0
    distance[S] = 0;

    // first pair in set in the form of (node_distance,node)
    st.insert(make_pair(0, S));
    while (!st.empty())
    {
        // top node from the set having minimum node distance value
        pair<int, int> top = *(st.begin());
        int distanceofnode = top.first;
        int node = top.second;
        st.erase(st.begin());

        // iterating through all the neighbouring nodes of top node
        for (auto neighbour : adj[node])
        {
            if (distanceofnode + neighbour[1] < distance[neighbour[0]])
            {
                auto record = st.find(make_pair(distance[neighbour[0]], neighbour[0]));
                if (record != st.end())
                {
                    st.erase(record);
                }
                // distance update
                distance[neighbour[0]] = distanceofnode + neighbour[1];

                // inserting record in set
                st.insert(make_pair(distance[neighbour[0]], neighbour[0]));
            }
        }
    }
    return distance;
}