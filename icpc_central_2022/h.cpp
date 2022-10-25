#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

using ll = long long;
using pii = pair<int, int>;
const int P = 1e9 + 7;

void solve()
{
    int n, e;
    cin >> n >> e;
    vector<vector<pii>> g(n);
    for (int i = 0; i < e; ++i)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].push_back({-1, v});
        g[v].push_back({-1, u});
    }
    int k;
    cin >> k;
    for (int i = 0; i < k; ++i)
    {
        int w, u, v;
        cin >> w >> u >> v;
        u--;
        v--;
        g[u].push_back({w, v});
        g[v].push_back({w, u});
    }

    priority_queue<pii, vector<pii>, greater<pii>> pq;
    vector<int> dist(n, -1);
    dist[0] = 0;
    pq.push({-1, 0});
    while (!pq.empty())
    {
        int u = pq.top().second;
        pq.pop();
        for (auto &[w, v] : g[u])
        {
            int t = max(dist[u] + 1, w);
            if (dist[v] < 0 || t < dist[v])
            {
                dist[v] = t;
                pq.push({dist[v], v});
            }
        }
    }
    cout << dist.back() << "\n";
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
