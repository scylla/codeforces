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
const int NMAX = 5005;

vii graph[NMAX];
bool vis[NMAX];
int N;
vi bestpath;
vi dfs(int v, int t, vi& path) {
	if(v == N && path.size() > bestpath.size()) {
		vi npath(path);
		bestpath = npath;
		return;
	}
	if(v == N && path.size() < bestpath.size()) return;
	for(int i = 0; i < graph[v].size(); ++i) {
		int next = graph[v][i].F;
		int cost = graph[v][i].S;
		if(t - cost >= 0) {
			path.eb(next);
			dfs(next, t - cost, path);
			path.pop_back();
		}
	}
}

void solve(int T) {
	vi path;
	path.eb(1);
	dfs(1, T, path);
	cout << bestpath.size() << endl;
	for(auto item : bestpath) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	fast_io
	int n, m, T;
	cin >> n >> m >> T;
	N = n;
	for(int i = 0; i < m; ++i) {
		int x, y, t;
		cin >> x >> y >> t;
		graph[x].eb(mp(y,t));
	}
	solve(T);
}