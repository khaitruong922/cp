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
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int segn = n - k + 1;
    vector<ll> seg(segn);
    for (int i = 0; i < k; ++i)
    {
        seg[0] += a[i];
    }
    for (int i = 1; i < segn; ++i)
    {
        seg[i] = seg[i - 1] + a[i + k - 1] - a[i - 1];
    }

    // maximum value at current position, if we have to use (0 - white, 1 - black)
    vector<vector<ll>> dp(segn, vector<ll>(2));

    dp[0][0] = max(seg[0], 0ll);
    dp[0][1] = max(-seg[0], 0ll);

    for (int i = 1; i < segn; ++i)
    {
        if (i - k < 0)
        {
            dp[i][0] = max(dp[i - 1][0], seg[i]);
            dp[i][1] = max(dp[i - 1][1], -seg[i]);
        }
        else
        {
            dp[i][0] = max(dp[i - 1][0], dp[i - k][1] + seg[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - k][0] - seg[i]);
        }
    }

    cout << max(dp[segn - 1][0], dp[segn - 1][1]) << "\n";
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
