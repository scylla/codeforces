// https://www.hackerrank.com/challenges/unbounded-knapsack

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
#define setminus(A) memset((A), -1, sizeof (A))

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
const int NMAX = 2002;
const int INF2 = 1e9 + 7;

pii dp[NMAX];

void solve(set<int>& si, int k) {
	for(int i = 0; i < NMAX; ++i) {
		dp[i] = mp(-1, INF2);
	}
	int n = si.size();
	dp[0].F = 0;
	dp[0].S = 0;
 	for(auto it = si.begin(); it != si.end(); ++it) {
		int item = *it;
		for(int j = item; j <= k; ++j) {
			if(dp[j].F == -1) {
				dp[j].F = (j/item)*item;
				dp[j].S = j/item;
			} else {
				if(dp[j-item].F == -1) {
					int sum = (j/item)*item;
					int ct = j/item;
					if(sum > dp[j].F) {
						dp[j].F = sum;
						dp[j].S = ct;
					} else if(sum == dp[j].F && dp[j].S > ct) {
						dp[j].S = ct;
					}
				} else {
					if(dp[j-item].F + item > dp[j].F) {
						dp[j].F = dp[j-item].F + item;
						dp[j].S = 1 + dp[j-item].S;
					} else if(dp[j-item].F + item == dp[j].F && dp[j].S > 1 + dp[j-item].S) {
						dp[j].S = 1 + dp[j-item].S;
					}
				}
			}
			// cout << "using " << item << " for sum " << j << " --  " <<  dp[j].F << " | " << dp[j].S << endl;
		}
	}
	if(dp[k].F > 0)
		cout << dp[k].F << endl;
	else cout << 0 << endl;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		set<int> si;
		int item;
		for(int i = 0; i < n; ++i) {
			cin >> item;
			si.insert(item);
		}
		solve(si, k);
	}
	return 0;
}