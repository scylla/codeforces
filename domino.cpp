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
const int NMAX = 502;

char maze[NMAX][NMAX];
pii dp[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    int R, C;
    cin >> R >> C;
    for(int i = 1; i <= R; i++) {
        for (int j = 1; j <= C; j++) {
            cin >> maze[i][j];
        }
    }
    for(int i = 2; i <= C; ++i) {
        if(maze[1][i] == '.' && maze[1][i-1] == '.')
            dp[1][i].F += (dp[1][i-1].F + 1);
				else  dp[1][i].F = dp[1][i-1].F;
    }
    for(int j = 2; j <= R; ++j) {
        if(maze[j][1] == '.' && maze[j-1][1] == '.')
            dp[j][1].S += (dp[j-1][1].S + 1);
				else dp[j][1].S = dp[j-1][1].S;
    }
		// horizontal case
    for(int i = 2; i <= R; ++i) {
        for(int j = 2; j <= C; ++j) {
            if(maze[i][j] == '.' && maze[i][j-1] == '.')
                dp[i][j].F += (dp[i][j-1].F + 1);
						else dp[i][j].F = dp[i][j-1].F;
        }
				for(int j = 2; j <= C; ++j)
						dp[i][j].F  += dp[i-1][j].F;
    }
		// vertical case
		for(int i = 2; i <= C; ++i) {
        for(int j = 2; j <= R; ++j) {
            if(maze[j][i] == '.' && maze[j-1][i] == '.')
                dp[j][i].S += (dp[j-1][i].S + 1);
						else dp[j][i].S = dp[j-1][i].S;
        }
				for(int j = 2; j <= R; ++j)
						dp[j][i].S  += dp[j][i-1].S;
    }
		int q;
		cin >> q;
		while(q--) {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			int res = dp[r2][c2].F - dp[r2][c1-1].F - dp[r1-1][c2].F + dp[r1-1][c1-1].F;
			res += dp[r2][c2].S - dp[r2][c1-1].S - dp[r1-1][c2].S + dp[r1-1][c1-1].S;
			for(int i = c1; i <= c2; ++i) {
				res -= maze[r1-1][i] == '.' && maze[r1][i] == '.'?1:0;
			}
			for(int i = r1; i <= r2; ++i) {
				res -= maze[i][c1-1] == '.' && maze[i][c1] == '.'?1:0;
			}
			cout << res << endl; 
 		}
    return 0;
}