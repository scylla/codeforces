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
const int NMAX = 5005;

int dpf[NMAX][NMAX];
int dpr[NMAX][NMAX];
vi charpos[62];

int charMap(char ch) {
	if(ch >= 'a' && ch <= 'z') return ch - 'a';
	else if(ch >= 'A' && ch <= 'Z') return ch - 'A' + 26;
	else return ch - '0' + 52;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string A, B;
	cin >> A >> B;
	int N = A.size();
	int M = B.size();

	for(int i = 0; i < M; ++i) {
		charpos[charMap(B.at(i))].eb(i+1);
	}

	for(int i = 1; i <= N; ++i) {
		for(int j = 1; j <= M; ++j) {
			if(A.at(i-1) == B.at(j-1)) {
				dpf[i][j] = dpf[i-1][j-1] + 1;
			} else dpf[i][j] = max(dpf[i-1][j], dpf[i][j-1]);
		}
	}

	int LCS = dpf[N][M];

	for(int i = N; i > 0; --i) {
		for(int j = M; j > 0; --j) {
			if(A.at(i-1) == B.at(j-1)) {
				dpr[i][j] = dpr[i+1][j+1] + 1;
			} else dpr[i][j] = max(dpr[i+1][j], dpr[i][j+1]);
		}
	}

	int ans = 0;

	for(int i = 0; i <= N; ++i) {
		for(int j = 0; j < 62; ++j) {
			for(int x : charpos[j]) {
				if(dpf[i][x-1] + dpr[i+1][x+1] == LCS) {
					ans++;
					break;
				}
			}
		}
	}

	cout << ans << endl;
	return 0;
}
