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
const int NMAX = 501;
int pos[NMAX][NMAX];
pii dp[NMAX][NMAX];

int getPerimeter(int x, int y) {
	return 2*(x + y - 2);
}

pii getCurBest(int m, int n) {
	pii result(0,0);
	cout << "m " << m << " n " << n << endl;
	for(int i = n - dp[m][n].F + 1; i < n; ++i) {
		int h = min(dp[m][i].S, dp[m][n].S);
		// cout << "i " << i << " h "  << h << endl;
		if(dp[m-h+1][n].F >= n-i+1 && h > 1 && n-i+1 > 1) {
			// cout << "n-i+1 " <<  n-i+1 << endl;
			if(getPerimeter(h, n-i+1) > getPerimeter(result.F, result.S)) {
				result.F = n-i+1;
				result.S = h;
			}
		}
	}
	cout << "result " <<  result.F << " -- " << result.S << endl;
	return result;
}

void solve(int rows, int cols) {
	for(int i = 1; i <= rows; ++i) {
		if(!pos[i][1]) {
			dp[i][1].S = dp[i-1][1].S + 1;
			dp[i][1].F = 1;
		}
	}
	for(int i = 1; i <= cols; ++i) {
		if(!pos[1][i]) {
			dp[1][i].F = dp[1][i-1].F + 1;
			dp[1][i].S = 1;
		}
	}
	for(int i = 2; i <= rows; ++i) {
		for(int j = 2; j <= cols; ++j) {
			if(!pos[i][j]) {
				dp[i][j].F = dp[i][j-1].F + 1;
				dp[i][j].S = dp[i-1][j].S + 1;
			}
		}
	}


	// for(int i = 1; i <= rows; ++i) {
	// 	for(int j = 1; j <= cols; ++j) {
	// 		cout << pos[i][j] << " ";
	// 	}
	// 	cout << endl;
	// }

	// for(int i = 1; i <= rows; ++i) {
	// 	for(int j = 1; j <= cols; ++j) {
	// 		cout << dp[i][j].F << "|" << dp[i][j].S << " ";
	// 	}
	// 	cout << endl;
	// }

	pii best_dims(0,0);
	for (int i = 2; i <= rows; ++i) {
		for(int j = 2; j <= cols; ++j) {
			if(!pos[i][j]) {
				if(dp[i][j].F > 1 && dp[i][j].S > 1) {
					pii cur_best = getCurBest(i, j);
					if(getPerimeter(cur_best.F, cur_best.S) > getPerimeter(best_dims.F, best_dims.S))
						best_dims = cur_best;
				}
			}
		}
	}

	if(best_dims.F <= 1 || best_dims.S <= 1)
		cout << "impossible" << endl;
	else cout << getPerimeter(best_dims.F, best_dims.S) << endl;

}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int M, N;
	cin >> M >> N;
	for(int i = 1; i <= M; ++i) {
		for(int j = 1; j <= N; ++j) {
			char ch;
			cin >> ch;
			if(ch == 'x') {
				pos[i][j] = 1;
			}
		}
	}
	solve(M, N);
	return 0;
}