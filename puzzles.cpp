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

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int arr[m];
	for(int i = 0; i < m; ++i) {
		cin >> arr[i];
	}
	sort(arr, arr + m);
	int best = arr[n-1] - arr[0];
	for(int i = 1; i <= m - n; ++i) {
		best = min(best, arr[i+n-1] - arr[i]);
	}
	cout << best << endl;
	return 0;
}