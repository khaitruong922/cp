#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

using ll = long long;
using ld = long double;

const int P = 1e9 + 7;

void solve()
{
    ll n;
    cin >> n;

    ld sum = (ld)1.0 * (n + 0) / (n + 1);
    cout << fixed << setprecision(10) << 1ll * (1ll - sum) * (ll)1e9 << "\n";
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
        freopen(argv[1], "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(nullptr);
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        solve();
    }
}
