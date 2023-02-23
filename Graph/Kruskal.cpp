#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int u;
    int v;
    int wt;

    node(int first, int second, int weight)
    {
        u = first;
        v = second;
        wt = weight;
    }
};

static bool comp(node a, node b)
{
    return a.wt < b.wt;
}
int findPar(int u, vector<int> parent)
{
    if (u == parent[u])
        return u;
    return findPar(parent[u], parent);
}
void unionn(int u, int v, vector<int> parent, vector<int> rank)
{
    u = findPar(u, parent);
    v = findPar(v, parent);

    if (rank[u] < rank[v])
        parent[u] = v;
    else if (rank[v] < rank[u])
        parent[v] = u;
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    vector<node> edges;
    int n = 3;
    int m = 3;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edges.push_back(node(a, b, c));
    }
    sort(edges.begin(), edges.end(), comp);

    vector<int> parent(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int, int>> mst;

    for (auto it : edges)
    {
        if (findPar(it.u, parent) != findPar(it.v, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.v});
            unionn(it.u, it.v, parent, rank);
        }
    }
    cout << "Cost of building mst -> " << cost << "\n";

    for (auto it : mst)
        cout << it.first << " " << it.second << "\n";

    return 0;
}