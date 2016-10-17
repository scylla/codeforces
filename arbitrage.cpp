// http://www.spoj.com/problems/ARBITRAG/

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
const int NMAX = 35;
double dp[NMAX][NMAX];

void solve(int n) {
	for(int k = 0; k < n; ++k) {
		for(int i = 0; i < n; ++i) {
			for(int j = 0; j < n; ++j) {
				dp[i][j] = max(dp[i][j], dp[i][k]*dp[k][j]);
			}
		}
	}
	bool arbitrage = false;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			if(i == j && dp[i][j] > 1.0) {
				arbitrage = true;
			}
		}
	}
	if(arbitrage) cout << "Yes" << endl;
	else cout << "No" << endl;
}

int main() {
	int n;
	cin >> n;
	int cnum = 0;
	while(n) {
		cout << "Case " << ++cnum << ": ";
		int count = 0;
		setzero(dp);
		map<string, int> cmap;
		string s;
		for(int i = 0; i < n; ++i) {
			cin >> s;
			cmap[s] = count++;
		}
		int q;
		cin >> q;
		for(int i = 0; i < q; ++i) {
			string s1, s2;
			double con;
			cin >> s1 >> con >> s2;
			dp[cmap[s1]][cmap[s2]] = con;
		}
		solve(n);
		cin >> n;
		cmap.clear();
	}
	return 0;
}