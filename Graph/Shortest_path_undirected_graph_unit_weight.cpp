
vector<int> shortestPath(vector<int> adj[], int src, int V, int dest)
{
    vector<int> ans;
    int vis[V] = {0};
    int parent{v} = {0};
    queue<int> q;

    q.push(src);
    parent[src] = -1;
    vis[src] = 1;

    while (!q.empty())
    {
        int front = q.front();
        q.pop();

        for (auto it : adj[front])
        {
            if (!vis[it])
            {
                vis[it] = 1;
                parent[it] = front;
                q.push(it);
            }
        }
    }

    int currNode = dest;
    ans.push_back(currNode);
    while (currNode != src)
    {
        currNode = parent[currNode];
        ans.push_back(currNode);
    }
    reverse(ans.begin(), ans.end());

    return ans;
}

// using bfs.Create a visited and parent array initialized with 0.Make a queue and mark the parent of souce node as -1 and visited source node=1.While the queue does not becomes empty,pop out the topNode and do the bfs.Iterate through the adjacent Nodes and if the adjacentNode is not visited then mark visited[adjacentNode]=1 and paren[adjacentNode]=topNode and push it in queue