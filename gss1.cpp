// http://www.spoj.com/problems/GSS1/

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
int arr[NMAX];
bool tree[NMAX << 1];

struct data{
	int pre, int suf, int sum, int ans;
} tree[NMAX << 1];

void combine(int node) {
	int lt = node << 1;
	int rt = node << 1 | 1;
	tree[node].sum = tree[lt].sum + tree[rt].sum;
	tree[node].pre = max(tree[lt].pre, tree[lt].sum + tree[rt].pre);
	tree[node].suf = max(tree[rt].suf, tree[rt].sum + tree[lt].suf);
	tree[node].ans = max(max(tree[lt].sum, tree[rt].sum), tree[lt].suf + tree[rt].pre);
}

data combineData(data l, data r) {
	data res;
	res.sum = l.sum + r.sum;
	res.pref = max (l.pref, l.sum + r.pref);
	res.suff = max (r.suff, r.sum + l.suff);
	res.ans = max (max (l.ans, r.ans), l.suff + r.pref);
	return res;
}

data makeData(int val) {
	data res;
	res.sum = val;
	res.pref = res.suff = res.ans = max (0, val);
	return res;
}

void setData(int node, int val) {
	tree[node].sum = val;
	tree[node].ans = tree[node].pre = tree[node].suf = max(0, val);
}

void build(int node, int tl, int tr) {
	if(tl == tr) {
		setData(node, arr[tl]);
	} else {
		int tm = (tl + tr)/2;
		build(node << 1, tl, tm);
		build(node << 1 | 1, tm + 1, tr);
		combine(node);
	}
}

void update(int node, int tl, int tr, int pos) {
	if(tl > tr || pos > tr || pos < tl) return;
	int tm = (tl + tr)/2;
	if(pos <= tm)
		update(node << 1, tl, tm, pos);
	else update(node << 1 | 1, tm +1, tr, pos);
	combine(node);
}

data query(int node, int tl, int tr, int i, int j) {
	if(tl > tr || tr < i || tl > j) return makeData(0);
	if(tl >= i && tr <= j) {
		return tree[node];
	} else {
		int tm = (tl + tr) / 2;
		return combineData(query(node << 1, tl, tm, i, j), query(node << 1 | 1, tm + 1, tr, i, j));
	}
}

int main() {
	fast_io

	return 0;
}



