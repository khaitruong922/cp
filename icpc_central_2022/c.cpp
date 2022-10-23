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

template <typename T>
struct bit
{
private:
    int n;

public:
    vector<T> a;
    void init(int k)
    {
        n = k;
        a.assign(n + 1, 0);
    }
    void update(int pos, T val)
    {
        for (; pos <= n; pos += pos & (-pos))
            a[pos] += val;
    }
    T query(int pos)
    {
        T ans = 0;
        for (; pos >= 1; pos -= pos & (-pos))
            ans += a[pos];
        return ans;
    }
};

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<pii> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }
    sort(a.begin(), a.end());

    vector<bit<ll>> b(k + 1);

    for (int i = 1; i <= k; ++i)
        b[i].init(n);

    for (int i = 0; i < n; ++i)
    {
        b[1].update(a[i].second, 1);
        for (int j = 2; j <= k; ++j)
            b[j].update(a[i].second, b[j - 1].query(a[i].second - 1));
    }

    ll ans = b[k].query(n);
    cout << ans << endl;
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
