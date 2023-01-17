bool DFS(vector<int> adj[], int src, int vis[], int parent[])
{

    vis[src] = 1;

    for (auto adjacent : adj[src])
    {

        if (!vis[adjacent])
        {

            parent[adjacent] = src;

            if (DFS(adj, adjacent, vis, parent))
            {

                return true;
            }
        }

        else if (vis[adjacent] && parent[src] != adjacent)
        {

            return true;
        }
    }

    return false;
}

bool isCycle(int V, vector<int> adj[])
{

    int parent[V];

    int vis[V] = {0};

    for (int i = 0; i < V; i++)
    {

        if (!vis[i])
        {

            parent[i] = -1;

            if (DFS(adj, i, vis, parent))
            {

                return true;
            }
        }
    }

    return false;
}