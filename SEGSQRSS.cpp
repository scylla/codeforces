// http://www.spoj.com/problems/SEGSQRSS/

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
#define endl "\n"

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
long arr[NMAX];
ll tree[NMAX << 1];
ll nsum[NMAX << 1];
ll lazy[NMAX << 1];
bool lazytype[NMAX << 1]; // true -- add false -- make same

void printTree() {
	for(int i = 1; i <= 16; ++i)
		cout << "i:" << i << " " << tree[i] << "|" << nsum[i] << " ";
	cout << endl;
	cout << "lazy \n";
	for(int i = 1; i <= 16; ++i)
		cout << "i:" << i << " -- " << lazy[i] << " ";
	cout << endl;
}

void build(int node, int tl, int tr) {
	if(tl == tr) {
		tree[node] = arr[tl]*arr[tl];
		nsum[node] = arr[tl];
	} else {
		int tm = (tl + tr)/2;
		build(node << 1, tl, tm);
		build(node << 1 | 1, tm + 1, tr);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
		nsum[node] = nsum[node << 1] + nsum[node << 1 | 1];
	}
}

// type 1 -- add x to all 2 -- change all to x
void update(int node, int tl, int tr, int i, int j, int type, int x) {
	if(lazy[node] != 0) {
		if(lazytype[node]) {
			tree[node] += (tr - tl + 1)*(lazy[node]*lazy[node]) + 2*nsum[node]*lazy[node];
			nsum[node] += (tr - tl + 1)*lazy[node];
		} else {
			nsum[node] = (tr - tl + 1)*lazy[node];
			tree[node] = (tr - tl + 1)*(lazy[node]*lazy[node]);
		}
		if(tl != tr) {
			if(lazytype[node]) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
				lazytype[node << 1] = lazytype[node << 1 | 1] = true;
			} else {
				lazy[node << 1] = lazy[node];
				lazy[node << 1 | 1] = lazy[node];
				lazytype[node << 1] = lazytype[node << 1 | 1] = false;
			}
		}
		lazy[node] = 0;
	}
	if(tl > tr || tr < i || tl > j) return;
	if(tl >= i && tr <= j) { // complete overlap
		if(type == 1) {
			tree[node] += (tr - tl + 1)*(x*x) + 2*nsum[node]*x;
			nsum[node] += (tr - tl + 1)*x;
			if(tl != tr) {
				lazy[node << 1] += x;
				lazy[node << 1 | 1] += x;
				lazytype[node << 1] = lazytype[node << 1 | 1] = true;
			}
		} else {
			nsum[node] = (tr-tl + 1)*x;
			tree[node] = (tr - tl + 1)*(x*x);
			if(tl != tr) {
				lazy[node << 1] = x;
				lazy[node << 1 | 1] = x;
				lazytype[node << 1] = lazytype[node << 1 | 1] = false;
			}
		}
		return;
	}

	int tm = (tl + tr) / 2;
	update(node << 1, tl, tm, i, j, type, x);
	update(node << 1 | 1, tm + 1, tr, i, j, type, x);
	tree[node] = tree[node << 1] + tree[node << 1 | 1];
	nsum[node] = nsum[node << 1] + nsum[node << 1 | 1];
}

int query(int node, int tl, int tr, int i, int j) {

	if(lazy[node] != 0) {
		if(lazytype[node]) {
			tree[node] += (tr - tl + 1)*(lazy[node]*lazy[node]) + 2*nsum[node]*lazy[node];
			nsum[node] += (tr - tl + 1)*lazy[node];
		} else {
			tree[node] = (tr - tl + 1)*(lazy[node]*lazy[node]);
			nsum[node] = (tr - tl + 1)*lazy[node];
		}
		if(tl != tr) {
			if(lazytype[node]) {
				lazy[node << 1] += lazy[node];
				lazy[node << 1 | 1] += lazy[node];
				lazytype[node << 1] = lazytype[node << 1 | 1] = true;
			} else {
				lazy[node << 1] = lazy[node];
				lazy[node << 1 | 1] = lazy[node];
				lazytype[node << 1] = lazytype[node << 1 | 1] = false;
			}
		}
		lazy[node] = 0;
	}

	if(tl > tr || tr < i || tl > j) return 0;
	// cout << "query " << node << " -- " << tl << "|" << tr << " " << i << "|" << j << endl;
	if(tl >= i && tr <= j) {
		return tree[node];
	}
	int tm = (tl + tr) / 2;
	return query(node << 1, tl, tm, i, j) + query(node << 1 | 1, tm + 1, tr, i, j);
}

int main() {
	fast_io
	int T;
	cin >> T;
	for(int t = 1; t <= T; ++t) {
		cout << "Case " << t << ":\n";
		int N, Q;
		cin >> N >> Q;
		setzero(tree);
		setzero(nsum);
		setzero(arr);
		setzero(lazytype);
		setzero(lazy);
		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
		}
		build(1, 1, N);
		// printTree();
		while(Q--) {
			int type;
			cin >> type;
			if(type == 0 || type == 1) {
				int p, q, x;
				cin >> p >> q >> x;
				update(1, 1, N, p, q, type, x);
				// printTree();
			} else {
				int p, q;
				cin >> p >> q;
				cout << query(1, 1, N, p, q) << endl;
				// printTree();
			}
		}
	}
	return 0;
}