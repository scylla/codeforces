// http://www.spoj.com/problems/MARTIAN/

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
#define mp(a, b) make_pair(a,b)
#define F first
#define S second
#define eb(x) emplace_back(x)
#define setzero(A) memset((A), 0, sizeof (A))
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
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int NMAX = 505;

int m;
int n;
int dp[NMAX][NMAX];
int br[NMAX][NMAX];
int yr[NMAX][NMAX];
int brdp[NMAX][NMAX];
int yrdp[NMAX][NMAX];

void solve() {

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			brdp[i][j] = brdp[i-1][j] + br[i][j];
		}
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			yrdp[i][j] = yrdp[i][j-1] + yr[i][j];
		}
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			dp[i][j] = max(brdp[i][j] + dp[i][j-1], yrdp[i][j] + dp[i-1][j]);
 		}
	}

	cout << dp[n][m] << endl;
}

int main() {
	fast_io
	while(true) {
		cin >> n >> m;
		if(n == 0 || m == 0) break;
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> yr[i][j];
			}
		}
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> br[i][j];
			}
		}
		solve();
	}
	return 0;
}