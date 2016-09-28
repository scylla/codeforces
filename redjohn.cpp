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
const int NMAX = 45;
const int PMAX = 217290;
int dp[2][NMAX];
bool isprime[PMAX];
int primecount[PMAX];

void preprocess() {
	fill(isprime, isprime + PMAX, true);
	isprime[0] = false;
	isprime[1] = false;
	for(int i = 2; i <= PMAX; ++i) {
		if(isprime[i]) {
			if(PMAX/i < i)
				break;
			for (int j = i*i; j <= PMAX; j += i) {
				isprime[j] = false;
			}
		}
	}

	for(int i = 2; i <= PMAX; ++i) {
		if(isprime[i])
			primecount[i] = primecount[i-1] + 1;
		else primecount[i] = primecount[i-1];
		// cout << primecount[i] << endl;
	}
}

int solve(int N) {
	memset(dp, 0, sizeof dp);
	for(int i = 1; i < 4; ++i) {
		dp[0][i] = 1;
		dp[1][i] = 0;
	}
	dp[0][4] = 1;
	dp[1][4] = 1;
	for(int i = 5; i <= N; ++i) {
		dp[0][i] = dp[0][i-1] + dp[1][i-1];
		dp[1][i] = dp[0][i-4] + dp[1][i-4];
	}
	return dp[0][N] + dp[1][N];
}

int main() {
	int T;
	cin >> T;
	preprocess();
	while(T--) {
		int N;
		cin >> N;
		int ways = solve(N);
		cout << primecount[ways] << endl;
	}
	return 0;
}