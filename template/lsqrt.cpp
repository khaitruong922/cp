#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// Source: https://codeforces.com/blog/entry/107717

ll lsqrt(ll x)
{
    ll ans = 0;
    for (ll k = 1LL << 30; k != 0; k /= 2)
    {
        if ((ans + k) * (ans + k) <= x)
        {
            ans += k;
        }
    }
    return ans;
}

int main()
{
    cout << lsqrt(0) << endl;
    cout << lsqrt(2) << endl;
    cout << lsqrt(4) << endl;
    cout << lsqrt(1e3) << endl;
    cout << lsqrt(1e17) << endl;
    cout << lsqrt(LLONG_MAX) << endl;
}