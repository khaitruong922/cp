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

ll cntpair(ll n)
{
    return n * (n - 1) / 2;
}

ll cnttrip(ll n)
{
    return n * (n - 1) * (n - 2) / 6;
}

void solve()
{
    int n;
    cin >> n;
    vector<ll> mod(5);
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        mod[x % 5]++;
    }

    ll ans = 0;
    ans += mod[0] * mod[1] * mod[4];
    ans += mod[0] * mod[2] * mod[3];
    ans += cntpair(mod[1]) * mod[3];
    ans += cntpair(mod[2]) * mod[1];
    ans += cntpair(mod[3]) * mod[4];
    ans += cntpair(mod[4]) * mod[2];
    ans += cnttrip(mod[0]);
    cout << ans << "\n";
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
