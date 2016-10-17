
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

int arrange(string A, int B) {
    int n = A.size();
    if(n < B) return -1;
    vector<pair<int, int>> presum(n, {0, 0});
    for(int i = 1; i <= n; ++i) {
        if(A[i-1] == 'W') {
            presum[i].F = 1 + presum[i-1].F;
            presum[i].S = presum[i-1].S;
         } else {
             presum[i].F = presum[i-1].F;
             presum[i].S = 1 + presum[i-1].S;
         }
    }
    vector<int> dp1(n+1, 0);
    vector<int> dp2(n+1, 0);

    for(int i = 1; i <= n; ++i) {
        dp1[i] = presum[i].F*presum[i].S;
        dp2[i] = dp1[i];
    }

    bool usingdp1 = true;

    for(int k = 2; k <= B; ++k) {
        int st = k-1;
        if(usingdp1) {
            for(int x = 0; x <= st; ++x) {
                dp1[x] = dp2[x];
            }
        } else {
            for(int x = 0; x <= st; ++x) {
                dp2[x] = dp1[x];
            }
        }
        for(int j = k; j <= n; ++j) {
            int mv = INT_MAX;
            for(int l = st; l < j; ++l) {
                if(usingdp1)
                    mv = min(mv, dp1[l] + (presum[j].F - presum[l].F)*(presum[j].S - presum[l].S));
                else  mv = min(mv, dp2[l] + (presum[j].F - presum[l].F)*(presum[j].S - presum[l].S));
            }
            if(usingdp1) {
                dp2[j] = mv;
            } else {
                dp1[j] = mv;
            }
            cout << k << "|" << j << "|" << mv << endl;
        }
        usingdp1 = !usingdp1;
    }

    if(usingdp1) {
        return dp1[n];
    } else return dp2[n];
}

int main() {
    string s;
    int n;
    cin >> s >> n;
    cout << arrange(s, n) << endl;
    return 0;
}