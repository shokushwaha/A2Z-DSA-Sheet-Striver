vector<int> topoSort(int V, vector<int> adj[])
{
    vector<int> inDegree(V);
    for (int i = 0; i < V; i++)
    {
        for (auto j : adj[i])
        {
            inDegree[j]++;
        }
    }
    vector<int> ans;
    queue<int> q;
    for (int i = 0; i < V; i++)
        if (inDegree[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto nbr : adj[frontNode])
        {
            inDegree[nbr]--;
            if (inDegree[nbr] == 0)
                q.push(nbr);
        }
    }
    return ans;
}