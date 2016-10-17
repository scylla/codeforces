// http://codeforces.com/problemset/problem/374/C

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
#define all(v) (v).begin(), (v).end()
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define endl "\n"
#define reset(a,b) memset(a,b,sizeof(a))

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
const int NMAX = 1e3 + 1;
char arr[NMAX][NMAX];
int lens[NMAX][NMAX];
bool vis[NMAX][NMAX];

vii dpos;
vii moves = {{0,1}, {1,0}, {-1, 0}, {0, -1}};

const char _A = 'A', _D = 'D', _I = 'I', _M = 'M';
int n, m;
bool iscycle, complete;

inline bool isValidMove(char cur, char nxt) {
	return (cur == _D && nxt == _I) || (cur == _I && nxt == _M) || (cur == _M && nxt == _A) || (cur == _A && nxt == _D) ;
}

int dfs(int ni, int nj) {
	if(loop) return 0;
	vis[ni][nj] = true;
	int ans = 0;
	char cur = arr[ni][nj];
	if(cur == _A) complete = true;
	for(auto it : moves) {
		int nxti = ni + it.F, nxtj = nj + it.S;
		char nxt = arr[nxti][nxtj];
		if(nxti >= 1 && nxti <= n && nxtj >= 1 && nxtj <= m && isValidMove(cur, nxt)) {
			if(vis[nxti][nxtj]) {
				loop = true;
				break;
			}
			if(!vis[nxti][nxtj] && lens[nxti][nxtj] != -1) {
				ans = max(ans, lens[nxti][nxtj]);
			} else {
				ans = max(ans, dfs(nxti, nxtj));
			}
		}
	}
	vis[ni][nj] = 0;
  return lens[ni][nj] = ans + (cur == _A)?1:0;
}

int main() {
	fast_io
	cin >> n >> m;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> arr[i][j];
			if(arr[i][j] == 'D') {
				dpos.eb(mp(i,j));
				dvis.eb(false);
				dcount.eb(0);
			}
		}
	}
	solve(n, m);
	return 0;
}