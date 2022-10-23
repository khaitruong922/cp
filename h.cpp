#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

using ll = long long;
using pii = pair<ll, ll>;

const int P = 1e9 + 7;

void dijkstra(int src, vector<vector<pii>> &g)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;
    int n = g.size();
    vector<ll> dist(n, LLONG_MAX);
    pq.push({0, src});
    dist[src] = 0;
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &adj : g[u])
        {
            int v = adj.second;
            ll w = dist[u] + 1;
            if (adj.first != 0)
            {
                w = max(adj.first, w);
            }
            if (w < dist[v])
            {
                dist[v] = w;
                pq.push({dist[v], v});
            }
        }
    }
    debug(dist);
    ll ans = dist[n - 1];
    if (ans == LLONG_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << ans << "\n";
    }
}

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<pii>> g(n);
    for (int i = 0; i < m; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back({0, v});
        g[v].push_back({0, u});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int u, v, w;
        cin >> w >> u >> v;
        u--, v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    dijkstra(0, g);
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
        freopen(argv[1], "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        solve();
    }
}
