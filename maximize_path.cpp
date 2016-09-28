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
const int NMAX = 5e5 + 5;

vi graph[NMAX];
bool visited[NMAX];
int best_so_far;
int max_node[1][3];

int dfs(int node) {
	visited[node] = true;
	if(graph[node].size() == 1 && visited[graph[node][0]]) {
		return 0;
	}
	vi lm;
	for(auto it = graph[node].begin(); it != graph[node].end(); ++it) {
		int pc;
		if(!visited[*it]) {
			int cur_best = 0;
			pc = dfs(*it) + 1;
			// cout << node << " " << *it << " " << pc << endl;
			if(lm.empty()) {
				lm.eb(pc);
				cur_best = pc;
			} else if (lm.size() == 1) {
				lm.eb(pc);
				cur_best = lm[0] + lm[1];
			} else if (lm.size() == 2) {
				lm.eb(pc);
				cur_best = lm[0] + lm[1] + lm[2];
			} else {
				int meidx = min_element(lm.begin(), lm.end()) - lm.begin();
				if(pc > lm[meidx]) {
					lm[meidx] = pc;
					cur_best = lm[0] + lm[1] + lm[2];
				}
			}
			if(cur_best > best_so_far) {
				best_so_far = cur_best;
			}
		}

	}
	int lb = *max_element(lm.begin(), lm.end());
	return lb;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		graph[x].eb(y);
		graph[y].eb(x);
	}
	dfs(1);
	cout << best_so_far << endl;
	return 0;
}