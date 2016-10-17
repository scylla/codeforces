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
int cp[NMAX][NMAX];
int P[NMAX][NMAX];
int n, m;

int dpr[NMAX][NMAX];
int dir[NMAX][NMAX];

void solver() {

	dpr[1][1] = cp[1][1];

	for(int i = 2; i <= m; ++i) {
		dpr[1][i] = dpr[1][i-1] + cp[1][i];
		dir[1][i] = 1; // right
	}

	for(int i = 2; i <= n; ++i) {
 		dpr[i][1] = dpr[i-1][1] + cp[i][1];
 		dir[i][1] = 2; // down
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout << dpr[i][j] << " ";
		}
		cout << endl;
	}

	for(int i = 2; i <= n; ++i) {
		for(int j = 2; j <= m; ++j) {
			int c1 = cp[i][j] + dpr[i-1][j] + (dir[i-1][j] == 1? P[i-1][j]: 0);
			int c2 = cp[i][j] + dpr[i][j-1] + (dir[i][j-1] == 2? P[i][j-1]: 0);
			// cout << i << " | " << j << " -- " << c1 << " | " << c2 << endl;
			if(c1 < c2) {
				dir[i][j] = 2;
				dpr[i][j] = c1;
			} else if(c2 < c1){
				dir[i][j] = 1;
				dpr[i][j] = c2;
			} else {
				dpr[i][j] = c1;
				dir[i][j] = 0;
			}
		}
	}

	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cout << dpr[i][j] << " ";
		}
		cout << endl;
	}

	cout << dpr[n][m] << endl;
}

int main() {

	fast_io
	int T;
	cin >> T;

	while(T--) {
		cin >> n >> m;
		setzero(cp);
		setzero(P);
		setzero(dpr);
		setzero(dir);

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> cp[i][j];
			}
		}

		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= m; ++j) {
				cin >> P[i][j];
			}
		}

		solver();
	}
	return 0;
}