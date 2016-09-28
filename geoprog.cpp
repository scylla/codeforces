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
#define pb(x) push_back(x)
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
const int NMAX = 2e5 + 1;
ll arr[NMAX];
inline bool inmap(map<ll, ll>& map1, ll x) {
    return map1.find(x) == map1.end() ? false: true;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    ll n,k;
    ll res = 0;
    map<ll, ll> rt, lt;
    cin >> n >> k;
    for(ll i = 1; i <= n; ++i) {
        cin >> arr[i];
        if(inmap(rt, arr[i]))
            rt[arr[i]] += 1;
        else rt[arr[i]] = 1;
    }
    for(ll i = 1; i <= n; ++i) {
        ll k1 = 0, k2 = 0;
        rt[arr[i]] -= 1;
        if(arr[i]%k == 0) {
            k1 = inmap(lt, arr[i]/k) ? lt[arr[i]/k] : 0;
            k2 = inmap(rt, arr[i]*k) ? rt[arr[i]*k] : 0;
            res += k1*k2;
            // cout << " -- " << arr[i] << endl;
            // cout << k1 << " " << k2 << " " << res << endl;
        }
        if(inmap(lt, arr[i]))
            lt[arr[i]] += 1;
        else lt[arr[i]] = 1;
    }
    cout << res << endl;
    return 0;
}