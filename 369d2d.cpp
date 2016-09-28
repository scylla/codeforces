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

// custom macros
#define mp(a, b) make_pair(a,b)
#define F first
#define S second
#define pb push_back
#define eb emplace_back

// custom types
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

// constants
const int MOD = 1e9 + 7;
ll INF = 1e15 + 7;
const int NMAX = 2*(1e5)+5;

// globals
int graph[NMAX];
int dfsn[NMAX];
int dfsseq[NMAX];
int dfn;
ll ans = 1;
int N;
int ce;
ll powers2[NMAX];

void powers(int limit) {
	powers2[0] = 1;
	for(int i = 1; i <= limit; ++i) {
		powers2[i] = ((powers2[i-1] % MOD) * 2) % MOD ;
	}
}

void dfs(int root, int seq) {
	dfsn[root] = ++dfn;
	dfsseq[root] = seq;
	int nxt = graph[root];
	if(dfsn[nxt] != 0 && dfsseq[nxt] == seq) {
		int len = dfsn[root] - dfsn[nxt] + 1;
		ans = ((ans % MOD) * (powers2[len] - 2 + MOD) % MOD) % MOD;
		ce += len;
	} else {
		if(dfsn[nxt] == 0)
			dfs(nxt, seq);
	}
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> N;
	powers(N);
	for(int i = 1; i <= N; ++i) {
		cin >> graph[i];
	}
	for(int i = 1; i <= N; ++i) {
		if(!dfsn[i] && !dfsn[graph[i]])
			dfs(i, i);
		else {
			if(!dfsn[i]) {
				dfsn[i] = ++dfn;
				dfsseq[i] = i;
			}
		}
	}
	cout << ((ans % MOD) * powers2[N-ce] % MOD) % MOD << endl;
	return 0;
}
