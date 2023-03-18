bool bfs(vector<int> adj[], int src, int vis[])
{
    queue<pair<int, int>> q;
    vis[src] = 1;
    q.push({src, -1});

    while (!q.empty())
    {
        int cur = q.front().first;
        int parent = q.front().second;
        q.pop();

        for (auto i : adj[cur])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push({i, cur});
            }
            else if (i != parent)
            {
                return true;
            }
        }
    }
    return false;
}
bool isCycle(int V, vector<int> adj[])
{
    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (bfs(adj, i, vis) == true)
                return true;
        }
    }
    return false;
}

// start with creating a visited array initialized with 0 then fo the bfs on graph if the node is not visited then call the bfs function.Make a queue in form of pair of {node,parent}.Push the {source,-1} in the queue.Then while the queue becomes empty pop out the top element in the form of curr=top.first() and parent=top.second().Then iterate for the adjacent nodes of curr node and if the adjacent node is not visited mark it visited and push it in queue {adjacentNode,curr} and if it is visited and the parent is not equal to the curr parent then return true.The basic idea is that the node is marked true and the parent is still to reach it.