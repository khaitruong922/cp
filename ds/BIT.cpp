#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct bit
{
private:
    vector<T> a;
    int n;

public:
    void init(int k)
    {
        n = k;
        a.assign(n + 1, 0);
    }
    void update(int pos, T val)
    {
        for (; pos <= n; pos += pos & (-pos))
            a[pos] += val;
    }
    T query(int pos)
    {
        T ans = 0;
        for (; pos >= 1; pos -= pos & (-pos))
            ans += a[pos];
        return ans;
    }
};