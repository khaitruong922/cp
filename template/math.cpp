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

ll cdiv(ll a, ll b)
{
    return (a + b - 1) / b;
}

ll power(ll a, ll b)
{
    ll res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2)
            res *= a;
    return res;
}

int main()
{
    cout << lsqrt(0) << endl;
    cout << lsqrt(2) << endl;
    cout << lsqrt(4) << endl;
    cout << lsqrt(1e3) << endl;
    cout << lsqrt(1e17) << endl;
    cout << lsqrt(LLONG_MAX) << endl;
    cout << "-----" << endl;
    cout << cdiv(2, 1) << endl;
    cout << cdiv(5, 2) << endl;
    cout << cdiv(6, 2) << endl;
    cout << "-----" << endl;
    cout << power(2, 4) << endl;
    cout << power(2, 0) << endl;
}