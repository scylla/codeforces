// http://www.spoj.com/problems/AGGRCOW/

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
#define set0(A) memset((A), 0, sizeof (A))
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
const ll INF = 1e15 + 7;
const int NMAX = 1e5 + 2;
const int INT_INF = 2*1e9 + 7;

int arr[NMAX];

void solve(int n, int c) {
	int lo = 0;
	int hi = arr[n-1] - arr[0] + 1;
	int best = lo;
	while(lo < hi) {
		int x = lo + (hi - lo)/2;
		int cows = 1;
		int lpos = 0;
		// cout << x << "|" << lo << "|" << hi << endl;
		for(int i = 1; i < n; ++i) {
			if((arr[i] - arr[lpos]) >= x) {
				lpos = i;
				cows++;
				// cout << cows << endl;
			}
			if(cows == c) break;
		}
		if(cows == c)
			best = max(best, x);
		if(cows < c) {
			hi = x;
		} else lo = x + 1;
	}
	cout << best << endl;
}

int main() {
	fast_io
	int t;
	cin >> t;
	while(t--) {
		int n, c;
		cin >> n >> c;
		for(int i = 0; i < n; ++i) {
			cin >> arr[i];
		}
		sort(arr, arr + n);
		solve(n, c);
	}
	return 0;
}