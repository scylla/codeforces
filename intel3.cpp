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
const int NMAX = 1 << 17;
int arr[NMAX];

int tree[NMAX << 1];
bool des[NMAX << 1];
int status[NMAX << 1];

void printTree() {
	for(int i = 1; i <= 18; ++i)
		cout << i << "|" << tree[i] << " ";
	cout << endl;
}


void build(int node, int tl, int tr) {
	if(tl == tr) { // leaf node
		tree[node] = arr[tl];
	} else {
		int tm = (tl + tr) / 2;
		build(node << 1, tl, tm);
		build(node << 1 | 1, tm+1, tr);
		tree[node] = tree[node << 1] + tree[node << 1 | 1];
	}
}

void updateTree(int node, int tl, int tr, int pos) {
	if(tl > tr || pos > tr || pos < tl) return;

	if(tl == tr) {
		des[node] = true;
		tree[node] = 0;
		status[node] = 3;
		return;
	}

	int tm = (tl+tr) / 2;

	if(pos <= tm) {
		updateTree(node << 1, tl, tm, pos);
	} else updateTree(node << 1 | 1, tm + 1, tr, pos);

	cout << (node << 1) << " " << des[node << 1] << " " << (node << 1 | 1) << " " << des[node << 1 | 1] << endl;
	if(des[node << 1] && des[node << 1 | 1]) {
		des[node] = true;
		tree[node] = 0;
		status[node] = 3;
	} else {
			if(des[node << 1]) {
				tree[node] = tree[node << 1 | 1];
				status[node] = 2; // rvalid
				cout << "f1" << endl;
			} else if(des[node << 1 | 1]) {
				tree[node] = tree[node << 1];
				status[node] = 1; // lvalid
				cout << "f2" << endl;
			} else {
				cout << "f3" << endl;
				if(status[node << 1] == 0 && status[node << 1 | 1] == 0) {
					tree[node] = tree[node << 1 | 1] + tree[node << 1];
					cout << "f4" << endl;
				} else if(status[node << 1] == 2 && status[node << 1 | 1] == 1) {
					tree[node] = tree[node << 1] + tree[node << 1 | 1];

					cout << "f5" << endl;
				} else if(status[node << 1] == 2 && status[node << 1 | 1] == 0) {
					tree[node] = tree[node << 1] + tree[node << 1 | 1];
					cout << "f6" << endl;
				} else if (status[node << 1] == 0 && status[node << 1 | 1] == 1) {
					tree[node] = tree[node << 1] + tree[node << 1 | 1];
					cout << "f7" << endl;
				} else {
					cout << "f8" << endl;
					tree[node] = max(tree[node << 1], tree[node << 1 | 1]);
					if(tree[node] == tree[node << 1]) {
						status[node] = 1;
					} else status[node] = 2;
				}
			}
	}

}

int query(int node, int tl, int tr) {
	if(tl > tr ) return 0;
	if(!des[node]) return tree[node];
	int tm = (tl + tr) / 2;
	int res1 = 0, res2 = 0;
	if(!des[node << 1])
		res1 = query(node << 1, tl, tm);
	if(!des[node << 1 | 1])
		res2 = query(node << 1 | 1, tl, tm);
	return max(res1, res2);
}

int main() {
	fast_io
		int N;
		cin >> N;

		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
		}

		build(1, 1, N);
		printTree();
		int Q = 1;
		while(Q--) {
			int q;
			cin >> q;
			updateTree(1, 1, N, q);
			printTree();
			cout << query(1, 1, N) << endl;
		}

	return 0;
}
