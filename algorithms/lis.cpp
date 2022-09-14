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

#define len(x) (int)(x).size()
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAX_N = 2e5 + 5;
ll a[MAX_N];

int lis(vector<int> &v) {
  int n = v.size();
  if (n == 0) return 0;
  vector<int> tail(n, 0);
  tail[0] = v[0];
  int length = 1;
  for (int i = 1; i < n; ++i) {
    if (v[i] < tail[0]) {
      tail[0] = v[i];
    } else if (v[i] > tail[length - 1]) {
      tail[length++] = v[i];
    } else {
      int idx =
          lower_bound(tail.begin(), tail.begin() + length, v[i]) - tail.begin();
      tail[idx] = v[i];
    }
    cout << tail << endl;
  }
  return length;
}

void solve() {
  vector<int> v{2, 5, 3, 7, 11, 8, 10, 13, 6};
  int ans = lis(v);
  cout << "Length of LIS: " << ans;
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
