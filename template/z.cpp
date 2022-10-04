#include <bits/stdc++.h>
using namespace std;

// Copy from here
using ll = long long;
const int P = 998244353;
int norm(int x)
{
    if (x < 0)
        x += P;
    if (x >= P)
        x -= P;
    return x;
}
template <class T>
T power(T a, ll b)
{
    T res = 1;
    for (; b; b /= 2, a *= a)
        if (b % 2)
            res *= a;
    return res;
}
struct Z
{
    int x;
    Z(int x = 0) : x(norm(x)) {}
    Z(ll x) : x(norm(x % P)) {}
    int val() const
    {
        return x;
    }
    Z operator-() const
    {
        return Z(norm(P - x));
    }
    Z inv() const
    {
        assert(x != 0);
        return power(*this, P - 2);
    }
    Z &operator*=(const Z &rhs)
    {
        x = ll(x) * rhs.x % P;
        return *this;
    }
    Z &operator+=(const Z &rhs)
    {
        x = norm(x + rhs.x);
        return *this;
    }
    Z &operator-=(const Z &rhs)
    {
        x = norm(x - rhs.x);
        return *this;
    }
    Z &operator/=(const Z &rhs)
    {
        return *this *= rhs.inv();
    }
    friend Z operator*(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res *= rhs;
        return res;
    }
    friend Z operator+(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res += rhs;
        return res;
    }
    friend Z operator-(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res -= rhs;
        return res;
    }
    friend Z operator/(const Z &lhs, const Z &rhs)
    {
        Z res = lhs;
        res /= rhs;
        return res;
    }
    friend istream &operator>>(istream &is, Z &a)
    {
        ll v;
        is >> v;
        a = Z(v);
        return is;
    }
    friend ostream &operator<<(ostream &os, const Z &a)
    {
        return os << a.val();
    }
};

int main()
{
    Z z = P + 1;
    cout << z << "\n";
    cout << z / 2 << "\n";
}