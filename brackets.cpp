// http://www.spoj.com/problems/BRCKTS/

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
const int NMAX = 1 << 15;
char arr[NMAX];
bool tree[NMAX << 1];
int ubr[NMAX << 1];
int ubl[NMAX << 1];
const char _LB = '(';
const char _RB = ')';

void printTree() {
	for(int i = 1; i <= 18; ++i)
		cout << ubl[i] << "|" << ubr[i] << " ";
	cout << endl;
}

void updateNode(int node) {
	int k = min(ubr[node << 1 | 1], ubl[node << 1]);
	ubl[node] = ubl[node << 1 | 1] + (ubl[node << 1] - k);
	ubr[node] = ubr[node << 1] + (ubr[node << 1 | 1] - k);
	if(ubl[node] == 0 && ubr[node] == 0) tree[node] = true;
	else tree[node] = false;
}

void build(int node, int tl, int tr) {
	if(tl == tr) { // leaf node
		tree[node] = false;
		if(arr[tl] == _LB) {
			ubl[node] = 1;
		} else {
			ubr[node] = 1;
		}
	} else {
		int tm = (tl + tr) / 2;
		build(node << 1, tl, tm);
		build(node << 1 | 1, tm+1, tr);
		updateNode(node);
	}
}

void updateTree(int node, int tl, int tr, int pos) {
	if(tl > tr || pos > tr || pos < tl) return;
	if(tl == tr) {
		if(ubl[node] == 1) {
			ubr[node] = 1;
			ubl[node] = 0;
		} else {
			ubl[node] = 1;
			ubr[node] = 0;
		}
		return;
	}
	int tm = (tl+tr) / 2;
	if(pos <= tm) {
		updateTree(node << 1, tl, tm, pos);
	} else updateTree(node << 1 | 1, tm + 1, tr, pos);
	updateNode(node);
}

int main() {
	fast_io
	for(int t = 1; t <= 10; ++t) {
		cout << "Test " << t << ": \n";
		int N;
		cin >> N;
		setzero(tree);
		setzero(ubr);
		setzero(ubl);
		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
		}
		build(1, 1, N);
		// printTree();
		int Q;
		cin >> Q;
		while(Q--) {
			int q;
			cin >> q;
			if(q == 0) {
				cout << (tree[1]? "YES" : "NO") << endl;
			} else {
				updateTree(1, 1, N, q);
				// printTree();
			}
		}
	}
	return 0;
}
