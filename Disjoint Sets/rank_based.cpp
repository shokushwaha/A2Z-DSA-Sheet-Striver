#include <bits/stdc++.h>
using namespace std;
class disjointSet
{

    vector<int> rank, parent;

public:
    disjointSet(int n)
    {
        // 1 based indexing graph
        rank.resize(n + 1, 0);
        parent.resize(n + 1);

        for (int i = 0; i < n + 1; i++)
            parent[i] = i;
    }

    int findUParent(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findUParent(parent[node]);
    }

    void unionByRank(int a, int b)
    {
        int ulp_a = findUParent(a);
        int ulp_b = findUParent(b);

        if (ulp_a == ulp_b) // both are already connected to same component
            return;

        if (rank[ulp_a] < rank[ulp_b])
            parent[ulp_a] = ulp_b;
        else if (rank[ulp_b] < rank[ulp_a])
            parent[ulp_b] = ulp_a;

        else
        {
            parent[ulp_b] = ulp_a;
            ranl[ulp_b]++;
        }
    }
};

int main()
{

    return 0;
}