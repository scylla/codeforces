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

typedef vector<pair<string, int>> vsi;

const int MOD = 1e9 + 7;
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int NMAX = 1002;

int dp[NMAX][NMAX];

void solve(string& s1, string& s2) {
	int n = s1.size();
	int m = s2.size();
	dp[0][0] = 0;
	for(int i = 1; i <= m; ++i) {
		dp[i][0] = ((s2[i-1] - '0') + dp[i-1][0]);
	}
	for(int i = 1; i <= n; ++i) {
		dp[0][i] = ((s1[i-1] - '0') + dp[0][i-1]);
	}
	// for(int i = 0; i <= m; ++i) {
		// for(int j = 0; j <= n; ++j) {
			// cout << dp[i][j] << " ";
		// }
		// cout << endl;
	// }
	for(int i = 1; i <= m; ++i) {
		for(int j = 1; j <= n; ++j) {
			// cout << s2[i-1] << " " << s1[j-1] << endl;
			if(s2[i-1]  == s1[j-1] ) {
				// cout << "equal " << endl;
				dp[i][j] = dp[i-1][j-1];
			} else {
				// cout << dp[i-1][j] + (s2[i-1] - '0') << " " << dp[i][j-1] + (s1[j-1] - '0') << endl;
				// cout << "distinct " << endl;
				dp[i][j] = min(dp[i-1][j] + (s2[i-1] - '0'), dp[i][j-1] + (s1[j-1] - '0'));
			}
			// cout << "i " << " j " << dp[i][j] << endl;
		}
	}

	// for(int i = 0; i <= m; ++i) {
	// 	for(int j = 0; j <= n; ++j) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	cout << dp[m][n] << endl;
}

int main() {
	fast_io
	int T;
	cin >> T;
	while(T--) {
		setzero(dp);
		string s1, s2;
		cin >> s1 >> s2;
		solve(s1, s2);
	}
	return 0;
}