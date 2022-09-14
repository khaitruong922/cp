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
void dbg_out() { cerr << endl; }
template <typename Head, typename... Tail>
void dbg_out(Head H, Tail... T)
{
    cerr << ' ' << H;
    dbg_out(T...);
}

#define ar array
#define ll long long
#define ld long double
#define fi first
#define se second
#define sza(x) ((int)x.size())
#define all(a) (a).begin(), (a).end()

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef pair<int, int> pii;

const ll MOD = 1e9 + 7;
const ll INF = 1e9;
const ld EPS = 1e-9;

const int MAX_N = 2e5 + 5;
int a[MAX_N];

class Trie
{
public:
    int cnt = 0;
    int prefcnt = 0;
    Trie *child[26];

    Trie()
    {
        for (int i = 0; i < 26; i++)
        {
            child[i] = nullptr;
        }
    }

    bool has(char c)
    {
        return child[c - 'a'] != nullptr;
    }

    Trie *get(char c)
    {
        if (!has(c))
            child[c - 'a'] = new Trie();
        return child[c - 'a'];
    }

    void insert(string s)
    {
        auto trie = this;
        for (char c : s)
        {
            trie->prefcnt++;
            trie = trie->get(c);
        }
        trie->prefcnt++;
        trie->cnt++;
    }

    int search(string s)
    {
        auto trie = this;
        for (char c : s)
        {
            if (!trie->has(c))
                return 0;
            trie = trie->get(c);
        }
        return trie->cnt;
    }

    int prefix(string s)
    {
        auto trie = this;
        for (char c : s)
        {
            if (!trie->has(c))
                return 0;
            trie = trie->get(c);
        }
        return trie->prefcnt;
    }

    void remove(string s)
    {
        int cnt = search(s);
        if (cnt == 0)
            return;
        auto trie = this;
        for (char c : s)
        {
            trie->prefcnt -= cnt;
            trie = trie->get(c);
        }
        trie->prefcnt -= cnt;
        trie->cnt -= cnt;
    }
};

void solve()
{
    Trie *trie = new Trie();
    trie->insert("hello");
    trie->insert("hello");
    cout << trie->search("hello") << endl;
    cout << trie->search("hell") << endl;
    cout << trie->prefix("hell") << endl;
    trie->insert("hell");
    cout << trie->search("hello") << endl;
    cout << trie->search("hell") << endl;
    cout << trie->prefix("hell") << endl;
    trie->remove("hello");
    cout << trie->search("hello") << endl;
    cout << trie->search("hell") << endl;
    cout << trie->prefix("hell") << endl;
}

int main(int argc, char *argv[])
{
    if (argc > 1)
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