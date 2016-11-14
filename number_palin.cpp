// http://codeforces.com/contest/245/problem/H

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
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int MAXN = 5005;

string s;
int n, q, dp[MAXN][MAXN];
bool isPal[MAXN][MAXN];

int main()
{
    ios::sync_with_stdio(0);
    cin >> s;
    n = (int)s.size();
    for (int i = 0 ; i < n ; i++)
    {
        isPal[i][i] = 1;
        dp[i][i] = 1;
        isPal[i+1][i] = 1;
    }
    for (int len = 2 ; len <= n ; len++)
        for (int start = 0 ; start <= n-len ; start++)
        {
            isPal[start][start+len-1] = isPal[start+1][start+len-2] & s[start] == s[start+len-1];
            dp[start][start+len-1] = dp[start][start+len-2] + dp[start+1][start+len-1] - dp[start+1][start+len-2] + isPal[start][start+len-1];
        }
    cin >> q;
    for (int i = 1 ; i <= q ; i++)
    {
        int l, r;
        cin >> l >> r;
        l--;
        r--;
        cout << dp[l][r] << endl;
    }
    return 0;
}