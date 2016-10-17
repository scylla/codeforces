// https://www.hackerrank.com/challenges/lucy-and-flowers

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <utility>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
const int NMAX = 5005;
int ncr[NMAX][NMAX];
int catalan[NMAX];

const int MOD = 1e9 + 9;

typedef long long int ll;

inline int modadd(int a, int b) {
   return a + b >= MOD? a + b - MOD : a + b;
}

void preprocess() {
  for(int i = 0; i < NMAX; ++i) {
     ncr[i][0] = 1;
  }
  for(int i = 1; i < NMAX; ++i) {
    for(int j = 1; j < NMAX; ++j) {
      ncr[i][j] = modadd(ncr[i-1][j], ncr[i-1][j-1]);
    }
  }
}

void processcatalan() {
  catalan[0] = catalan[1] = 1;
  for(int i = 2; i < NMAX; ++i) {
    int base = i-1;
    for(int j = 0; j <= base; ++j) {
      catalan[i] = modadd(catalan[i], ((ll)catalan[j]*(ll)catalan[base-j]) % MOD);
    }
  }
}

void solve(int n) {
  int ans = 0;
  for(int i = 1; i <= n ; ++i) {
    ans = modadd(((ll)ncr[n][i] * (ll)(catalan[i])) % MOD, ans);
  }
  cout << ans << endl;
}

int main() {
  fast_io
  preprocess();
  processcatalan();
  int t;
  cin >> t;
  while(t--) {
    int n;
    cin >> n;
    if(n == 1) cout << 1 << endl;
    else solve(n);
  }
  return 0;
}

