#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
int p[N];

void init()
{
    memset(p, -1, sizeof p);
}

int find(int u)
{
    if (p[u] < 0)
        return u;
    return p[u] = find(p[u]);
}

void uni(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v)
        return;
    if (p[u] > p[v])
        swap(u, v);
    p[u] += p[v];
    p[v] = u;
}

bool check(int u, int v)
{
    return find(u) == find(v);
}