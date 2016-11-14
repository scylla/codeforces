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
#define NMAX 100001

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;

struct customCompare {
	bool operator()(pii& p1, pii& p2) {
		return p1.F > p2.F;
	}
};

int main() {
	priority_queue<pii, vector<pii>, customCompare> pq;
	int n, m;
	cin >> n >> m;
	int extra = 0;
	int x;
	map<int, int> pmap;
	vector<int> arr(n+1);
 	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
	}
	for(int i = 1; i <= n; ++i) {
		if(i <= m)
			fre[i].
	}
	return 0;
}