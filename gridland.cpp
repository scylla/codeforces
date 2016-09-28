// https://www.hackerrank.com/contests/world-codesprint-7/challenges/gridland-metro

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
typedef pair<pii, int> ppi;


const int MOD = 1e9 + 7;
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int NMAX = 1002;
ppi tracks[NMAX];

bool comparePii(ppi& p1, ppi &p2) {
	if(p1.S < p2.S) return true;
	else if(p1.S == p2.S) {
		if(p1.F.F < p2.F.F) return true;
		else if(p1.F.F == p2.F.F) return p1.F.S < p2.F.S;
		else return false;
	}
	else return false;
}

int main() {
	ios_base:: sync_with_stdio(0);
	cin.tie(0);
	ll ans = 0;
	ll n, m;
	int k;
	cin >> n >> m >> k;
	for(int i = 1; i <= k; ++i) {
		int r, c1, c2;
		cin >> r >> c1 >> c2;
		tracks[i] = mp(mp(c1, c2), r);
	}
	if(k == 0)
		cout << m * n << endl;
	else {
		sort(tracks + 1, tracks + k + 1, comparePii);
		// for(int i = 1; i <= k; ++i) {
			// cout << tracks[i].S << " " << tracks[i].F.F << " " << tracks[i].F.S << endl;
		// }
		ans = m*n;
		int cr = tracks[1].S;
		int cre = tracks[1].F.S;
		int crs = tracks[1].F.F;
		ans -= (tracks[1].F.S - tracks[1].F.F + 1);
		for(int i = 2; i <= k; ++i) {
			if(tracks[i].S == cr) {
				if(tracks[i].F.F <= cre && tracks[i].F.F >= crs) { // overlapping track and not covered
					if(tracks[i].F.S > cre) {
						// cout << "overlap " << tracks[i].S << " " << tracks[i].F.S - cre << endl;
						ans -= (tracks[i].F.S - cre);
						cre = tracks[i].F.S;
					}
				} else {
					// cout << "same row non-overlap " << (tracks[i].F.S - tracks[i].F.F + 1) << endl;
					ans -= (tracks[i].F.S - tracks[i].F.F + 1);
					cre = tracks[i].F.S;
					crs = tracks[i].F.F;
				}
			} else {
				// cout << "new row " << tracks[i].S << " " << (tracks[i].F.S - tracks[i].F.F + 1) << endl;
				ans -= (tracks[i].F.S - tracks[i].F.F + 1);
				cre = tracks[i].F.S;
				crs = tracks[i].F.F;
				cr = tracks[i].S;
			}

		}
		cout << ans << endl;
	}
	return 0;
}
