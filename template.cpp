#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << "{";
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
    return os << "}";
}

#define ll long long
#define fi first
#define se second

#define len(x) (int)(x).size()

typedef vector<int> vi;
typedef vector<vi> vii;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;

void solve()
{
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
        freopen(argv[1], "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        // cout << "Case #" << t << "\n";
        solve();
    }
}
