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
#define NMAX 100001

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;
ll counts[NMAX];
ll res[NMAX];

int main() {	
	ios::sync_with_stdio(false);	
	int n, x;
	cin >> n;
	int maxi = 0; 
	for(int i = 0; i < n; ++i) {
		cin >> x;
		maxi = max(maxi, x);
		counts[x] += 1;		
	}
	res[1] = counts[1];
	for(ll i = 2; i <= maxi; ++i) {
		res[i] = max(res[i-1], res[i-2] + i*counts[i]);
	}
	cout << res[maxi] << endl;
	return 0;
}