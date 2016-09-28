// https://www.codechef.com/IPC15AMR/problems/ENTRY

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
const int NMAX = 1 << 17;

ll tree[NMAX << 1];
ll lazy[NMAX << 1];
int arr[NMAX];
ll cache[NMAX << 1][10];

void build(int node, int tl, int tr) {
	if(tl == tr) {
		// tree[node] = arr[tl];
		cache[node][0] = 1;
	} else {
		int tm = (tr + tl)/2;
		build(node << 1, tl, tm);
		build(node << 1 | 1, tm+1, tr);
		for(int i = 0; i <= 9; ++i) {
			cache[node][i] = cache[node << 1][i] + cache[node << 1 | 1][i];
		}
	}
}

void update(int node, int tl, int tr, int i, int j) {
	// cout << "in up " << node << " -- " << tl << " -- " << tr << " -- " << i << " -- " << j << endl;
	if(lazy[node] != 0) {
		ll t0 = cache[node][0];
		ll t1 = cache[node][1];
		ll t2 = cache[node][2];
		ll t3 = cache[node][3];
		ll t4 = cache[node][4];
		ll t5 = cache[node][5];
		ll t6 = cache[node][6];
		ll t7 = cache[node][7];
		ll t8 = cache[node][8];
		ll t9 = cache[node][9];
		ll lz = lazy[node];
		// cout << "in up 1" << endl;
		cache[node][lz % 10] = t0;
		cache[node][(lz+1) % 10] = t1;
		cache[node][(lz+2) % 10] = t2;
		cache[node][(lz+3) % 10] = t3;
		cache[node][(lz+4) % 10] = t4;
		cache[node][(lz+5) % 10] = t5;
		cache[node][(lz+6) % 10] = t6;
		cache[node][(lz+7) % 10] = t7;
		cache[node][(lz+8) % 10] = t8;
		cache[node][(lz+9) % 10] = t9;
		// cout << "in up 2" << endl;
		if(tl != tr) {
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
		}
		lazy[node] = 0;
	}

	if(tl > tr || tr < i || tl > j)
		return;

	if(tl >= i && tr <= j) {
		long temp = cache[node][9];
		for(int k = 9; k > 0; --k) {
			cache[node][k] = cache[node][k-1];
		}
		cache[node][0] = temp;
		if(tr != tl) {
			lazy[node << 1] += 1;
			lazy[node << 1 | 1] += 1;
		}
		return;
	}

	int tm = (tl+tr)/2;
	update(node << 1, tl ,tm, i, j);
	update(node << 1 | 1, tm+1, tr, i, j);
	for(int k = 0; k <= 9; ++k) {
		cache[node][k] = cache[node << 1][k] + cache[node << 1 | 1][k];
	}
}

ll query(int node, int tl, int tr, int i, int j) {
	if(tl > tr || i > tr || j < tl) return 0;
	if(lazy[node] != 0) {
		ll t0 = cache[node][0];
		ll t1 = cache[node][1];
		ll t2 = cache[node][2];
		ll t3 = cache[node][3];
		ll t4 = cache[node][4];
		ll t5 = cache[node][5];
		ll t6 = cache[node][6];
		ll t7 = cache[node][7];
		ll t8 = cache[node][8];
		ll t9 = cache[node][9];
		ll lz = lazy[node];
		cache[node][lz % 10] = t0;
		cache[node][(lz+1) % 10] = t1;
		cache[node][(lz+2) % 10] = t2;
		cache[node][(lz+3) % 10] = t3;
		cache[node][(lz+4) % 10] = t4;
		cache[node][(lz+5) % 10] = t5;
		cache[node][(lz+6) % 10] = t6;
		cache[node][(lz+7) % 10] = t7;
		cache[node][(lz+8) % 10] = t8;
		cache[node][(lz+9) % 10] = t9;
		if(tl != tr) {
			lazy[node << 1] += lazy[node];
			lazy[node << 1 | 1] += lazy[node];
		}
		lazy[node] = 0;
	}
	ll ans = 0;
	if(tl >= i && tr <= j) {
		for(int k = 0; k <= 9; ++k) {
			ans += k*cache[node][k];
		}
		return ans;
	}
	int tm = (tl + tr) / 2;
	return query(node << 1, tl, tm, i, j) + query(node << 1 | 1, tm+1, tr, i, j);

}

int main() {
	fast_io
	int N, Q;
	cin >> N >> Q;
	build(1, 1, N);
	while(Q--) {
		int ty, p, q;
		cin >> ty >> p >> q;
		if(ty == 1) {
			// cout << "up " << endl;
			update(1, 1, N, p, q);
		} else {
			// cout << "query " << endl;
			cout << query(1, 1, N, p, q) << endl;
		}
	}
	return 0;
}