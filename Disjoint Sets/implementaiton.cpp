#include <bits/stdc++.h>
using namespace std;
int parent[10];

// self parent
void make(int v)
{
    parent[v] = v;
}

// find parent
int find(int v)
{
    if (v == parent[v])
        return v;

    return find(parent[v]);
}

// make union
void unionFind(int a, int b)
{
    a = find(a);
    b = find(b);
    if (a != b)
    {
        a = parent[b];
    }
}
int main()
{
    return 0;
}