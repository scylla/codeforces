#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<long, long> pll;

const int NMAX = 1002;
bool valid[NMAX][NMAX];
int n, m;

struct cell {
	int val, x, y;
	cell(int v, int x1, int y1) {
		val = v;
		x = x1;
		y = y1;
	}
};

struct compareCell {
	bool operator()(cell& c1, cell& c2){
		return c1.val > c2.val;
	}
};

typedef priority_queue<cell, vector<cell>, compareCell> minheap;

void solve(minheap& pq) {
	vi path;
	while(!pq.empty()) {
		cell top = pq.top();
		pq.pop();
		if(valid[top.x][top.y]) {
			path.pb(top.val);
			// update 1
			for(int i = top.x - 1; i > 0; --i)
				for(int j = top.y + 1; j <= m; ++j)
					valid[i][j] = false;
			// update 2
			for(int i = top.x + 1; i <= n; ++i)
				for(int j = 1; j < top.y; ++j)
					valid[i][j] = false;
		}
	}
	sort(path.begin(), path.end());
	for(auto item : path) {
		cout << item << " ";
	}
	cout << endl;
}

int main() {
	fast_io
	cin >> n >> m;
	memset(valid, 1, sizeof valid);
	minheap pq;
	int vv;
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j <= m; ++j) {
			cin >> vv;
			pq.push(cell(vv, i, j));
		}
	}
	solve(pq);
}