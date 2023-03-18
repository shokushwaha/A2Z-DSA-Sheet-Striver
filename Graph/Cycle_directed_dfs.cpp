bool dfs(int node, int vis[], vector<int> adj[], int pathVis[])
{
    vis[node] = 1;
    pathVis[node] = 1;
    for (auto i : adj[node])
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, pathVis) == true)
                return true;
        }
        else if (pathVis[i] == 1)
            return true;
    }
    pathVis[node] = 0;
    return false;
}
bool isCyclic(int V, vector<int> adj[])
{
    int vis[V] = {0}, pathVis[V] = {0};
    for (int i = 0; i < V; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, vis, adj, pathVis))
                return true;
        }
    }
    return false;
}

// start with creating two arrays visited and pathVisited initialized with 0 and do dfs.If the node is not viisted call the dfs function.Mark the visited[node]=pathVisited[node]=1 and iterate througth the adjacentNodes and if the adjacentNode is not vistied call the dfs for adjacentNode and if the node is visited already check whether the pathVisited is true or not and if it is true then the cycle exists and while returning from the function call mark the pathVisited[node]=0 again and return false;