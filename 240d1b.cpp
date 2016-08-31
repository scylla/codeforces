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
const int NMAX = 2002;

ll dp[NMAX][NMAX];

int main() {
    ios_base::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        dp[i][1] = 1;
    }
    for(int i = 1; i <= n; i++) {
        for(int j = 2; j <= k; j++) {
            for(int m = i; m <= n; m += i){
                dp[m][j] += dp[i][j-1];
                dp[m][j] %= MOD; 
            }
        }
    }
    ll res = 0;
    for(int i = 1; i <= n; ++i) {
        res += dp[i][k];
        res %= MOD;
    }
    cout << res << endl;
    return 0;
}
