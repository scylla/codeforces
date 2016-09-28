// http://www.spoj.com/problems/HORRIBLE/

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

void build(int v, int tl, int tr) {
	if(tl == tr) {
		tree[v] = arr[tl];
	} else {
		int tm = (tl+tr)/2;
		build(v << 1, tl, tm);
		build(v << 1 | 1, tm + 1, tr);
		tree[v] = tree[v << 1] + tree[v << 1 | 1];
	}
}

void update(int v, int tl, int tr, int i, int j, ll value) {
	// cout << "at " << v << endl;
	// cout << "query " << i << "|" << j << " range " << tl << "|" << tr << endl;
	if(lazy[v] != 0) {
		if(tl != tr) { // not a leaf node
			lazy[v << 1] += lazy[v];
			lazy[v << 1 | 1] += lazy[v];
			tree[v] += (tr-tl+1)*lazy[v];
		} else {
			tree[v] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(tl > j || tr < i || tl > tr) {	// out of range
		// cout << "oooooooooooooooooo " << endl;
		return;
	}
	if(tl >= i && tr <= j) { // current segment fully in range

		if(tl != tr) {
			lazy[v << 1] += value;
			lazy[v << 1 | 1] += value;
		}
		tree[v] += (tr-tl+1)*value;
		// cout << "val at " << v << " :: " << tree[v] << endl;
		return;
	}
	int tm = (tl+tr)/2;
	update(v << 1, tl, tm, i, j, value);
	update(v << 1 | 1, tm + 1, tr, i, j, value);
	tree[v] = tree[v << 1] + tree[v << 1|1];
	// cout << "val at " << v << " :: " << tree[v] << endl;
}

ll query(int v, int tl, int tr, int i, int j) {
	if(tl > tr || tl > j || tr < i) return 0;
	if(lazy[v] != 0) {
		if(tl != tr) { // not a leaf node
			lazy[v << 1] += lazy[v];
			lazy[v << 1 | 1] += lazy[v];
			tree[v] += (tr-tl+1)*lazy[v];
		} else {
			tree[v] += lazy[v];
		}
		lazy[v] = 0;
	}
	if(tl >= i && tr <= j) return tree[v];
	int tm = (tl + tr) / 2;
	return query(v << 1, tl, tm, i, j) + query(v << 1 | 1, tm + 1, tr, i, j);
}

void printTree() {
	for(int i = 1; i <= 20; ++i) {
		cout << i << " --- " << tree[i] << " | " << lazy[i] << endl;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		setzero(tree);
		setzero(lazy);
		int N, C;
		cin >> N >> C;
		while(C--) {
			int qtype;
			cin >> qtype;
			if(qtype == 0) {
				int p, q;
				ll v;
				cin >> p >> q >> v;
				update(1, 1, N, p, q, v);
				// printTree();
			} else {
				int p, q;
				cin >> p >> q;
				cout << query(1, 1, N, p, q) << endl;
			}
		}
	}
	return 0;
}