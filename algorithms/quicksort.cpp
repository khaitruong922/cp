
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

int p1(vector<int> &v, int l, int r) {
  int pivot = v[l];
  int j = l;
  for (int i = l; i <= r; ++i) {
    if (pivot > v[i]) {
      j++;
      swap(v[i], v[j]);
    }
  }
  swap(v[j], v[l]);
  return j;
}

void qs1(vector<int> &v, int l, int r) {
  if (l < r) {
    int j = p1(v, l, r);
    qs1(v, l, j - 1);
    qs1(v, j + 1, r);
  }
}

int p2(vector<int> &v, int l, int r) {
  int pivot = v[r];
  int j = r;
  for (int i = r; i >= l; --i) {
    if (pivot < v[i]) {
      j--;
      swap(v[i], v[j]);
    }
  }
  swap(v[r], v[j]);
  return j;
}

void qs2(vector<int> &v, int l, int r) {
  if (l >= r) return;
  int p = p2(v, l, r);
  qs2(v, l, p - 1);
  qs2(v, p + 1, r);
}

void solve() {
  vector<int> v{6, 5, 4, 3, 2, 1, 0};
  auto v1 = v;
  qs1(v, 0, v.size() - 1);
  cout << v << "\n";
  auto v2 = v;
  qs2(v2, 0, v2.size() - 1);
  cout << v2 << "\n";
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
