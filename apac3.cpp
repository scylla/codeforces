#include <cmath>
#include <map>
#include <vector>
#include <iomanip>
#include <queue>
#include <deque>
#include <set>
#include <stack>
#include <sstream>
#include <assert.h>
#include <functional>
#include <climits>
#include <cstring>
#include <utility>
#include <iostream>
#include <fstream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <string>
#include <list>
#include <fstream>
#include <algorithm>
#include <unordered_map>
#define mp(a, b) make_pair(a,b)
#define F first
#define S second
#define eb(x) emplace_back(x)
#define set0(A) memset((A), 0, sizeof (A))
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<vl> vvl;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
typedef vector<vii> vvp;

const int MOD = 1e9 + 7;
const ll INF = 1e15 + 7;
const int NMAX = 4001;
const int INT_INF = 2*1e9 + 7;

int dp[NMAX];
map<vector<int>, int> cmap;

int main() {
  fast_io
  int T;
  cin >> T;
  string s;
  for(int t = 1; t <= T; ++t) {
  	cout << "Case #" << t << ": ";
  	int N, M;
    cin >> N >> M;
    cmap.clear();
    for(int i = 0; i < N; ++i) {
      cin >> s;
      vector<int> A(26, 0);
      for(char ch : s) A[ch - 'a']++;
      cmap[A]++;
    }
    for(int i = 0; i < M; ++i) {
      cin >> s;
      dp[0] = 1;
      for(int j = 0; j < s.size(); ++j) {
        dp[j+1] = 0;
        vector<int> A(26, 0);
        for(int k = 0; k < 20 && j-k >= 0; ++k) {
          A[s[j-k] - 'a']++;
          auto it = cmap.find(A);
          if(it != cmap.end()) dp[j+1] = (dp[j+1] + ((ll)dp[j-k]*(ll)it->second) % MOD) % MOD;
        }
      }
      cout << dp[s.size()] << " ";
    }
    cout << endl;
  }
	return 0;
}