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
#define setzero(A) memset((A), 0, sizeof (A))
#define all(v) (v).begin(), (v).end()

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
const int NMAX = 1e6 + 2;

int powers2[NMAX];
int sz[NMAX];
int so[NMAX];

void preprocess() {
	powers2[0] = 1;
	for(int i = 1; i <= NMAX; ++i) {
		powers2[i] = (int)((long)(powers2[i-1])*2ll) % MOD;
	}
}

void solve(string& a, string& b) {
	reverse(all(a));
	reverse(all(b));
	const int n = 314159;
	for(int i = 0; i < b.size(); ++i) {
		sz[i] = b[i] - '0';
		if(i > 0)
			sz[i] += sz[i-1];
	}



}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	preprocess();
	while(T--) {
		string a, b;
		setzero(sz);
		setzero(so);
		cin >> a >> b;
		if(a.size() < b.size()) {
			solve(a, b);
		} else {
			solve(b, a);
		}
		preprocess();
	}
	return 0;
}