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

ll powmod(ll a, ll b, ll p)
{
    ll res = 1;
    a %= p;
    while (b > 0)
    {
        if (b % 2)
            res = (res * a) % p;
        b >>= 1;
        a = (a * a) % p;
    }
    return res;
}

// Assume that gcd(x,p) == 1
ll modinv(ll x, ll p)
{
    return powmod(x, p - 2, p);
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
    cout << "-----" << endl;
    cout << powmod(2, 0, 1e9 + 7) << endl;
    cout << powmod(2, 4, 1e9 + 7) << endl;
    cout << powmod(2, 29, 1e9 + 7) << endl;
    cout << "----" << endl;
    cout << modinv(1, 1e9 + 7) << endl;
    cout << modinv(2, 1e9 + 7) << endl;
    cout << modinv(3, 1e9 + 7) << endl;
}