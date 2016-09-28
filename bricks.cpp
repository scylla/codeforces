// https://www.hackerrank.com/challenges/play-game

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
const int NMAX = 1e5 + 2;
int arr[NMAX];
pair<ll, int> dp[NMAX];
ll sum[NMAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		set0(dp);
		set0(arr);
		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
			sum[i] = sum[i-1] + arr[i];
		}
		for(int i = N, j = 1; i > 0; --i, ++j) {
			if(j <= 3) {
				dp[j].F = sum[N] - sum[i-1];
				dp[j].S = 0;
			} else {
				int back = 1;
				ll profit = dp[j-1].F;
				for(int k = 2; k <= 3; ++k) {
					if(dp[j-k].F < profit) {
						profit = dp[j-k].F;
						back = k;
					}
				}
				dp[j].F = sum[i+back-1] - sum[i-1] + dp[dp[j-back].S].F;
				dp[j].S = j - back;
			}
		}
		cout << dp[N].F << endl;
	}
	return 0;
}