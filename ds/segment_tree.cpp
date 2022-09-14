#include <bits/stdc++.h>
using namespace std;

class SegmentTree
{

public:
    vector<int> v;
    vector<int> st;
    SegmentTree(vector<int> &v)
    {
        this->v = v;
        build();
    }
    void build()
    {
        int n = this->v.size();
        int height = (int)ceil(log2(n));
        int size = (1 << (height + 1)) - 1;
        vector<int> st(size, 0);
        this->st = st;
        build(0, n - 1, 0);
    }
    int build(int l, int r, int i)
    {
        if (l == r)
            return st[i] = v[l];
        int mid = getMid(l, r);
        return st[i] = build(l, mid, i * 2 + 1) + build(mid + 1, r, i * 2 + 2);
    }

    int getSum(int l, int r)
    {
        return getSum(0, size() - 1, l, r, 0);
    }

    int getSum(int ss, int se, int qs, int qe, int si)
    {
        if (qs <= ss && qe >= se)
            return st[si];
        if (se < qs || ss > qe)
            return 0;
        int mid = getMid(ss, se);
        return getSum(ss, mid, qs, qe, si * 2 + 1) +
               getSum(mid + 1, se, qs, qe, si * 2 + 2);
    }
    void update(int i, int val)
    {
        int diff = val - v[i];
        v[i] = val;
        update(0, size() - 1, i, diff, 0);
    }
    void update(int ss, int se, int i, int diff, int si)
    {
        if (i < ss || i > se)
            return;
        st[si] += diff;
        if (ss == se)
            return;
        int mid = getMid(ss, se);
        update(ss, mid, i, diff, si * 2 + 1);
        update(mid + 1, se, i, diff, si * 2 + 2);
    }
    int getMid(int l, int r)
    {
        return l + (r - l) / 2;
    }
    int size()
    {
        return v.size();
    }
};

int main()
{
    vector<int> v = {1, 2, 9, 20, 5, 4, 6, 8, 100, 7};
    SegmentTree *st = new SegmentTree(v);
    for (int i = 0; i < st->st.size(); ++i)
    {
        cout << st->st[i] << " \n"[i == st->st.size() - 1];
    }
    cout << st->getSum(0, 1) << "\n";
    cout << st->getSum(2, 4) << "\n";
    cout << st->getSum(3, 7) << "\n";
    cout << st->getSum(0, 9) << "\n";
    st->update(4, 10);
    cout << "After update: \n";
    cout << st->getSum(0, 1) << "\n";
    cout << st->getSum(2, 4) << "\n";
    cout << st->getSum(3, 7) << "\n";
    cout << st->getSum(0, 9) << "\n";
}