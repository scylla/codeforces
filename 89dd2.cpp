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

const int MOD = 1e8;
ll INF = 1e15 + 7;
const int NMAX = 101;

int dp[NMAX][NMAX][2];

int main() {
	int n1, n2, k1, k2;
	cin >> n1 >> n2 >> k1 >> k2;
	for(int i = 1; i <= min(n1, k1); ++i) {
		dp[i][0][0] = 1;
	}
	for(int i = 0; i <= min(n2, k2); ++i) {
		dp[0][i][1] = 1;
	}
	for(int i = 1; i <= n1; ++i) {
		for(int j = 1; j <= n2; ++j) {
			for(int k = 1; k <= min(i, k1); ++k) {
				dp[i][j][0] = (dp[i][j][0] + dp[i-k][j][1]) % MOD;
			}
			for(int k = 1; k <= min(j, k2); ++k) {
				dp[i][j][1] = (dp[i][j-k][0] + dp[i][j][1]) % MOD;
			}
		}
	}
	ll ans  = dp[n1][n2][0] + dp[n1][n2][1];
	cout << ans % MOD << endl;
	return 0;
}