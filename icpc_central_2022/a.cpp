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

const int N = 301;
int dp[N][N][N][2];

int k;
string s;
int dfs(int l, int r, int q, int t, bool qturn)
{
    if (t >= k)
        return 1;
    if (q >= k)
        return 0;
    if (dp[l][r][qturn ? q : t][qturn] != -1)
        return dp[l][r][qturn ? q : t][qturn];
    if (qturn)
        return dp[l][r][q][qturn] = dfs(l + 1, r, q + (s[l] == 'B'), t, !qturn) || dfs(l, r - 1, q + (s[r] == 'B'), t, !qturn);
    return dp[l][r][t][qturn] = dfs(l + 1, r, q, t + (s[l] == 'B'), !qturn) && dfs(l, r - 1, q, t + (s[r] == 'B'), !qturn);
}

void solve()
{
    memset(dp, -1, sizeof dp);
    int n;
    cin >> n >> k >> s;
    if (dfs(0, n - 1, 0, 0, true))
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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
