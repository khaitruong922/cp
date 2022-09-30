#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "aaabaacaabaaab";
    string t = "aaab";
    int n = s.size();
    int m = t.size();
    // Construct LPS array
    vector<int> lps(m);
    int i = 1;
    int j = 0;
    while (i < m)
    {
        if (t[i] == t[j])
        {
            j++;
            lps[i] = j;
            i++;
        }
        else if (j > 0)
        {
            j = lps[j - 1];
        }
        else
        {
            lps[i] = 0;
            i++;
        }
    }
    i = 0;
    j = 0;
    while ((n - i) >= (m - j))
    {
        if (s[i] == t[j])
        {
            i++;
            j++;
            if (j == m)
            {
                cout << "Found at " << i - m << "\n";
                j = lps[j - 1];
            }
        }
        else
        {
            if (j > 0)
                j = lps[j - 1];
            else
                i++;
        }
    }
}