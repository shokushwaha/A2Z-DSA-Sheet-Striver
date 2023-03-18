int spanningTree(int V, vector<vector<int>> adj[])
{
    // priotity queue storing pair in the form of {weight,node} in min heap
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    // visited array to keep track of all the visited nodes
    vector<int> vis(V, 0);

    // pushing root in min heap
    pq.push({0, 0});

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

// start with creating a min heap and a visied array initialized with 0.Min heap in the form of pair {dist,node}.Then push {0,root} in min heap.While min heap is not empty,pop out the top element from the min heap and if it is visited then continue for the next iteration and if it is not visited mark it visited and add the weight to the answer and iterate through the adjacent nodes.If the adjacent nodes are non visited push  them in min heap and repeat till the min heap becomes empty