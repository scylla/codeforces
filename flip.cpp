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
#define NMAX 101

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;
int arr[NMAX];
pii states[NMAX];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	int c0 = 0, c1 = 0;
	for(int i = 1; i <= n; ++i) {
		cin >> arr[i];
		if(arr[i] == 0)
			c0++;
		else c1++;
		states[i] = mp(c0, c1); 
	}
	states[0] = mp(0, 0);
	int best = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i; j <= n; ++j) {
			best = max(best, states[i-1].S + (states[j].F - states[i-1].F) + (states[n].S - states[j-1].S));
		}
	}
	if(n == 1)
		cout << 1 - states[1].S << endl;
	else if(states[n].S == n)
		cout << best-1 << endl;
	else cout << best << endl;
	return 0;
}