// https://www.hackerrank.com/challenges/square-subsequences

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
const int NMAX = 210;
double dp[NMAX][NMAX];
char str[NMAX];

int add(int a, int b) {
	return a + b >= MOD ? a + b - MOD : a + b;
}

int subtract(int a, int b) {
	return a >= b ? a - b : a - b + MOD;
}

int solve(int n, char *S1, int m, char *T1) {
	for(int i = 0; i <= n; ++i) {
		dp[i][m] = 1;
	}
	for(int i = 0; i <= m; ++i) {
		dp[n][i] = 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		for (int j = m - 1; j >= 0; j--) {
			dp[i][j] = add(dp[i + 1][j], dp[i][j + 1]);
			dp[i][j] = subtract(dp[i][j], dp[i + 1][j + 1]);
			if (S1[i] == T1[j]) {
				dp[i][j] = add(dp[i][j], dp[i + 1][j + 1]);
			}
		}
	}
	int res = 0;
	for (int j = 0; j < m; j++) {
		if (S1[0] == T1[j]) {
			res = add(res, dp[1][j + 1]);
		}
	}
	return res;
}

int main() {
	int t;
	cin >> t;
	while(t--) {
		int ans = 0;
		scanf("%s", str);
		int n = strlen(str);
		for(int m = 1; m < n; ++m) {
			ans = add(ans, solve(n-m, str + m, m, str));
		}
		cout << ans << endl;
	}
	return 0;
}
