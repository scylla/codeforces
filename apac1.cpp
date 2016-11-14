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
const int NMAX = 2001;
const int INT_INF = 2*1e9 + 7;

double dp[NMAX][NMAX];

int main() {
	int T;
	cin >> T;
	cout << fixed << showpoint;
  cout << setprecision(8);
	for(int i = 1; i < NMAX; ++i) {
		dp[i][0] = 1;
	}
	for(int i = 1; i < NMAX; ++i) {
		for(int j = 1; j < NMAX; ++j) {
			double pa = (double)i/(i+j);
			double pb = 1 - pa;
			if(i > j) {
				dp[i][j] = pa*dp[i-1][j] + pb*dp[i][j-1];
			}
		}
	}
	for(int t = 1; t <= T; ++t) {
		int n, m;
		cin >> n >> m;
		cout << "Case #" << t << ": " << dp[n][m] << endl;
	}
	return 0;
}