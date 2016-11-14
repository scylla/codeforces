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
#define mp(a, b) make_pair(a,b)
#define F first
#define S second

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

const int NMAX = 52;
using namespace std;

char arr[NMAX][NMAX];
bool vis[NMAX][NMAX];

vector<pair<int, pii>> lakes;

int dirx[4] = {0, 1, -1, 0};
int diry[4] = {-1, 0, 0, 1};

int n, m, k;
int result;
int cnt;
int adj;

bool valid(int i, int j) {
	if(i < 0 || i >= n || j < 0 || j >= m) return false;
	else return true;
}

bool dfs(int x, int y, bool start) {
	// cout << "dfs " << x << " :: " << y << endl;
	vis[x][y] = true;
	if(x == 0 || y == 0 || x == n-1 || y == m-1) adj = 1;
	bool lake = true;
	for(int i = 0; i < 4; ++i) {
		int nx = x + dirx[i];
		int ny = y + diry[i];
		// cout << "checking " << nx << " : " << ny << endl;
		if(valid(nx, ny) && arr[nx][ny] == '.' && !vis[nx][ny]) {
			lake = lake && dfs(nx, ny, false);
		}
	}
	// cout << "dfs done " << x << " :: " << y << endl;
	// cout << "is lake " << lake << endl;

	if(lake) cnt++;
	if(lake && start && adj == 0) {
		// cout << "added lake size " << pr << " at " << x << " : " << y << endl;
		lakes.push_back({cnt, {x, y}});
	}
	return lake;
}

bool customCompare(pair<int, pii>& p1, pair<int, pii>& p2) {
	return p1.F < p2.F;
}

void fill_lakes(int x, int y) {
	arr[x][y] = '*';
	for(int i = 0; i < 4; ++i) {
		int nx = x + dirx[i];
		int ny = y + diry[i];
		if(valid(nx, ny) && arr[nx][ny] == '.') {
			fill_lakes(nx, ny);
		}
	}
}

int main() {
	cin >> n >> m >> k;
	memset(vis, 0, sizeof vis);
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			// cout << arr[i][j];
		}
		// cout << endl;
	}
	for(int i = 1; i < n - 1; ++i) {
		for(int j = 1; j < m - 1; ++j) {
			if(arr[i][j] == '.' && !vis[i][j]) {
				cnt = 0;
				adj = 0;
				dfs(i, j, true);
			}
		}
	}

	sort(lakes.begin(), lakes.end(), customCompare);
	int num_lakes = lakes.size();
	int idx = 0;
	// cout << num_lakes << endl;
	while(num_lakes > k) {
		num_lakes--;
		result += lakes[idx].F;
		fill_lakes(lakes[idx].S.F, lakes[idx].S.S);
		idx++;
	}
	cout << result << endl;
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < m; ++j) {
			cin >> arr[i][j];
			cout << arr[i][j];
		}
		cout << endl;
	}
	return 0;
}