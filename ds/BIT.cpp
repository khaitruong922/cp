#include <bits/stdc++.h>
using namespace std;

class BIT
{

public:
    vector<int> a;
    vector<int> ft;
    BIT(vector<int> &a)
    {
        this->a = a;
        buildTree();
    }
    void buildTree()
    {
        ft = a;
        ft.insert(ft.begin(), 0);
        int n = size();
        for (int i = 1; i <= n; ++i)
        {
            int p = i + (i & -i);
            if (p <= n)
            {
                ft[p] += ft[i];
            }
        }
    }
    int prefixSum(int i)
    {
        int tot = 0;
        while (i > 0)
        {
            tot += ft[i];
            i -= i & -i;
        }
        return tot;
    }

    int rangeSum(int l, int r)
    {
        return prefixSum(r + 1) - prefixSum(l);
    }

    void displayArray()
    {
        int n = size();
        for (int i = 0; i < n; ++i)
            cout << a[i] << " \n"[i == n - 1];
    }

    void displayTree()
    {
        int n = size();
        for (int i = 1; i <= n; ++i)
            cout << ft[i] << " \n"[i == n];
    }

    void update(int i, int val)
    {
        int diff = val - a[i];
        a[i] = val;
        i++;
        int n = size();
        while (i <= n)
        {
            ft[i] += diff;
            i += i & -i;
        }
    }

    int size()
    {
        return ft.size() - 1;
    }
};

int main()
{
    vector<int> v = {7, 2, 3, 1, 5, 10, 3, 12, 18};
    BIT *bit = new BIT(v);
    bit->displayArray();
    bit->displayTree();
    cout << bit->prefixSum(2) << endl;
    cout << bit->prefixSum(3) << endl;
    cout << bit->prefixSum(5) << endl;
    cout << bit->prefixSum(6) << endl;
    cout << bit->rangeSum(2, 3) << endl;
    cout << bit->rangeSum(1, 5) << endl;
    cout << bit->rangeSum(4, 7) << endl;
    bit->update(3, 100);
    bit->displayArray();
    bit->displayTree();
    cout << bit->prefixSum(2) << endl;
    cout << bit->prefixSum(3) << endl;
    cout << bit->prefixSum(5) << endl;
    cout << bit->prefixSum(6) << endl;
    cout << bit->rangeSum(2, 3) << endl;
    cout << bit->rangeSum(1, 5) << endl;
    cout << bit->rangeSum(4, 7) << endl;
}