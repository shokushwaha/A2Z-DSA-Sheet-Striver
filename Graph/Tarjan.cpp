// detect all the bridges in a graph
int timer = 0;
void dfs(int node, int parent, vector<int> &vis, vector<int> &tin, vector<int> &low, vector<int> adj[], vector<vector<int>> &bridges)
{

    vis[node] = 1;
    tin[node] = low[node] = timer;
    timer++;

    for (auto it : adj[node])
    {
        if (it == parent)
            continue;
        if (vis[it] == 0)
        {
            dfs(it, node, vis, tin, low, adj, bridges);
            low[node] = min(low[node], low[it]);
            // may exist a bridge  node----it
            // if adjacent node low time is smaller or equal to current time of node so it can reach again via some path and if it is greater than there is a bridge
            if (low[it] > tin[node])
                bridges.push_back({it, node});
        }
        else
        {
            low[node] = min(low[node], low[it]);
        }
    }
}

vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{

    vector<vector<int>> bridges;

    vector<int> tin(n);
    vector<int> low(n);
    vector<int> vis(n, 0);

    vector<int> adj[n];

    for (auto it : connections)
    {
        adj[it[0]].push_back(it[1]);
        adj[it[1]].push_back(it[0]);
    }

    dfs(0, -1, vis, tin, low, adj, bridges);

    return bridges;
}
// low time stores lowest of insertion time of all adjacent nodes except parent

// create three arrays tin to store the reach time of a node and low to store the lowest to reach a node and visited array initialized with 0.Then create a adjacency list from the given connections and call the dfs.In the dfs,mark the visited[node]=true and track a timer variable and set low[node]=tin[node]=timer and increase the timer.Then iterate through the adjacnet nodes of the node,if the adjacent node is parent itself then continue to the next iteration and if the adjacent node is not visited,call the dfs with adjacnetNode and the node as parent and set low[node]=min(low[node],low[it]) and if low[it]>tin[node] then bridge is present ie basically if the low time of the adjacent node is smaller than the tin of node then there is no bridge as we can reah it by other way