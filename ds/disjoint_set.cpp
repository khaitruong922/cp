#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) {
  return os << '(' << p.first << ", " << p.second << ')';
}
template <typename T_container, typename T = typename enable_if<
                                    !is_same<T_container, string>::value,
                                    typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v) {
  os << '{';
  string sep;
  for (const T &x : v) os << sep << x, sep = ", ";
  return os << '}';
}

#define ar array
#define ll long long
#define ld long double
#define pb push_back
#define ppb pop_back
#define fi first
#define se second

#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<string> vs;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAX_N = 2e5 + 5;
ll a[MAX_N];

int find(int i, vector<int> &parent) {
  if (parent[i] < 0) return i;
  return parent[i] = find(parent[i], parent);
}

void solve() {
  int n = 8;
  vector<pii> paths{{1, 2}, {3, 4}, {5, 6}, {7, 8}, {2, 4},
                    {2, 5}, {1, 3}, {6, 8}, {5, 7}};
  vector<int> parent(n + 1, -1);
  cout << parent << '\n';
  for (auto &p : paths) {
    int u = find(p.fi, parent);
    int v = find(p.se, parent);

    if (u == v) continue;
    if (parent[u] > parent[v]) swap(u, v);
    parent[u] += parent[v];
    parent[v] = u;
  }
  cout << parent << endl;
  for (int i = 1; i <= n; i++)
    if (parent[i] > 0) parent[i] = find(parent[i], parent);
  cout << parent << endl;
}

int main(int argc, char *argv[]) {
  if (argc >= 2) freopen(argv[1], "r", stdin);
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int tc = 1;
  // cin >> tc;
  for (int t = 1; t <= tc; t++) {
    solve();
  }
}
