// https://www.hackerrank.com/challenges/grid-walking

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
const int NMAX = 11;
const int MMAX = 302;
const int DMAX = 102;
const int NDIMS = 11;

int ncr[MMAX][MMAX]; // nCr
int moves[NDIMS][MMAX]; // moves for each dimension for each step size
int mvdims[MMAX][DMAX]; // moves possible for DMAX with MMAX moves
int posi[NDIMS];
int dimrange[NDIMS];
ll results[NDIMS][MMAX];

void calculateNCR() {
	ncr[0][0] = 1;
	for(int i = 1; i <= MMAX; ++i) {
		ncr[i][0] = 1;
		for(int j = 1; j <= i; ++j) {
			ncr[i][j] = (ncr[i-1][j-1] + ncr[i-1][j]) % MOD;
		}
	}
}

void calculateRangeForDim(int dim, int M) {
	set0(mvdims);
	mvdims[0][posi[dim]] = 1;
	moves[dim][0] = 1;
	for(int i = 1; i <= M; ++i) {
		for(int  j = 1; j <= dimrange[dim]; ++j) {
			if(j-1 > 0)
				mvdims[i][j] = (mvdims[i][j] % MOD + mvdims[i-1][j-1]) % MOD;
			if(j+1 <= dimrange[dim])
				mvdims[i][j] = (mvdims[i][j] + mvdims[i-1][j+1]) % MOD;
			moves[dim][i] = (moves[dim][i] % MOD + mvdims[i][j] % MOD) % MOD;
		}
	}
}

void solve(int N, int M) {
	for(int i = 0; i <= M; ++i) {
		results[1][i] = moves[1][i];
	}
	for(int i = 2; i <= N; ++i) {
		results[i][0] = 1;
		for(int j = 1; j <= M; ++j) {
			for(int k = 0; k <= j; ++k) {
				results[i][j] = (results[i][j] + (((ncr[j][k] * results[i-1][k]) % MOD) * moves[i][j-k]) % MOD) % MOD;
				// cout << results[i][j] << " | " << results[i-1][k] << " | " << ncr[j][k] << " | " << moves[i][j-k] << endl;
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	calculateNCR();
	while(T--) {
		int N, M;
		cin >> N >> M;
		set0(moves);
		set0(posi);
		set0(dimrange);
		set0(results);
		for(int i = 1; i <= N; ++i) {
			cin >> posi[i];
		}
		for(int i = 1; i <= N; ++i) {
			cin >> dimrange[i];
		}
		for(int i = 1; i <= N; ++i)
			calculateRangeForDim(i, M);
		solve(N, M);
		cout << results[N][M] << endl;
	}
	return 0;
}