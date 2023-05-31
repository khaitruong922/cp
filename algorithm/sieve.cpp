#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#include "debug.h"
#else
#define debug(x...)
#endif

using ll = long long;
const int N = sqrt(1e6);
vector<int> mp(N + 1, 1);
vector<int> primes;

void init() {
    for (int i = 2; i <= N; ++i) {
        if (mp[i]) {
            primes.push_back(i);
        }
        for (auto p : primes) {
            if (i * p > N) break;
            mp[i * p] = 0;
            if (i % p == 0) break;
        }
    }
}

int main(int argc, char *argv[]) { init(); }
