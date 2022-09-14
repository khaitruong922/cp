#include <bits/stdc++.h>

using namespace std;

template <typename A, typename B>
ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template <typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type>
ostream &operator<<(ostream &os, const T_container &v)
{
    os << '{';
    string sep;
    for (const T &x : v)
        os << sep << x, sep = ", ";
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

int lowerBound(vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] >= x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int upperBound(vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (v[mid] > x)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return l;
}

int binarySearch(vector<int> &v, int x)
{
    int l = 0, r = v.size() - 1;
    int mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (v[mid] == x)
        {
            break;
        }
        else if (v[mid] < x)
            l = mid + 1;
        else
            r = mid - 1;
    }
    // Find first element of duplicate sequence
    while (mid > 0)
    {
        if (v[mid - 1] == x)
            mid--;
        else
            break;
    }
    if (v[mid] == x)
        return mid;
    return -1;
}

void solve()
{
    vector<int> v{2, 2, 4, 6, 8, 10, 12, 12, 100};
    vector<int> tc = {1, 2, 7, 8, 12, 13, 100, 101};
    for (auto x : tc)
    {
        int myLowerBound = lowerBound(v, x);
        int myUpperBound = upperBound(v, x);
        int expectedLowerBound = lower_bound(v.begin(), v.end(), x) - v.begin();
        int expectedUpperBound = upper_bound(v.begin(), v.end(), x) - v.begin();
        int myIndex = binarySearch(v, x);
        if (myLowerBound == expectedLowerBound)
            cout << "Lower bound of " << x << " is " << myLowerBound << endl;
        else
            cout << "Incorrect lower bound for " << x << " . Expected: " << expectedLowerBound << ". Found: " << myLowerBound << endl;

        if (myUpperBound == expectedUpperBound)
            cout << "Upper bound of " << x << " is " << myUpperBound << endl;
        else
            cout << "Incorrect upper bound for " << x << " . Expected: " << expectedUpperBound << ". Found: " << myUpperBound << endl;

        if (find(v.begin(), v.end(), x) != v.end())
        {
            if (myIndex != -1)
                cout << "Found " << x << " at index " << myIndex << endl;
            else
                cout << "Incorrect index for " << x << " . Expected: " << find(v.begin(), v.end(), x) - v.begin() << ". Found: " << myIndex << endl;
        }
        else
        {
            if (myIndex == -1)
                cout << "Did not find " << x << endl;
            else
                cout << "Incorrect index for " << x << " . Expected: " << -1 << ". Found: " << myIndex << endl;
        }
    }
}

int main(int argc, char *argv[])
{
    if (argc >= 2)
        freopen(argv[1], "r", stdin);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int tc = 1;
    // cin >> tc;
    for (int t = 1; t <= tc; t++)
    {
        solve();
    }
}