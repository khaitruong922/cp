#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> buildST(int a[], int n)
{
    int MAX_POWER_OF_2 = 32;
    vector<vector<int>> st(n, vector<int>(MAX_POWER_OF_2));
    for (int i = 0; i < n; ++i)
        st[i][0] = a[i];
    for (int j = 1; (1 << j) <= n; ++j)
    {
        for (int i = 0; i + (1 << j) < n; ++i)
        {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    return st;
}

int query(int l, int r, vector<vector<int>> &st)
{
    r++;
    int j = (int)log2(r - l);
    return min(st[l][j], st[r - (1 << j)][j]);
}

int main()
{
    int a[] = {7, 2, 3, 0, 5, 10, 3, 12, 18};
    vector<pair<int, int>> tc = {{0, 1}, {0, 4}, {1, 2}, {5, 7}, {2, 6}, {7, 8}};
    auto st = buildST(a, sizeof a);
    for (auto &[l, r] : tc)
    {
        cout << "Minimum from " << l << " to " << r << " is " << query(l, r, st) << endl;
    }
}