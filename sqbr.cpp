// http://www.spoj.com/problems/SQRBR/

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

int main() {
	fast_io
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		vector<bool> pos(2*n+1, false);
		for(int i = 0; i < k; ++i) {
			int ps;
			cin >> ps;
			pos[ps] = true;
		}
		vector<vector<int>> dp(2*n+2, vector<int>(2*n+2, 0));
		dp[1][1] = 1;
		for(int i = 2; i <= 2*n; ++i) {
			for(int j = 0; j <= n; ++j) {
				if(pos[i]) {
					dp[i][j] = j > 0 ? dp[i-1][j-1] : 0;
				} else {
					dp[i][j] = (j > 0 ? dp[i-1][j-1] : 0) + dp[i-1][j+1];
				}
				// cout << i << " " << j << " -- " << dp[i][j] << endl;
			}

		}
		cout << dp[2*n][0] << endl;
	}
	return 0;
}