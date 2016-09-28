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
const int NMAX = 5*1e4 + 2;

int arr[NMAX];

int main() {
    int T;
    cin >> T;
    while(T--) {
       int N;
       cin >> N;
       memset(arr, 0, sizeof arr);
       for(int i = 1; i <= N; ++i) {
           cin >> arr[i];
       }
       ll ans = 0l;
       ll mv = arr[N];
       ll lso_far = 0l;
       ll bc = 0l;
       for(int i = N-1; i >= 1; --i) {
           if(arr[i] <= mv) {
               lso_far += arr[i];
               bc++;
           } else {
               if(bc > 0) {
                   ans += mv*bc - lso_far;
                   lso_far = 0;
                   bc = 0;
               }
               mv = arr[i];
           }
       }
       if(bc > 0) ans += mv*bc - lso_far;
       cout << ans << endl;
    }
    return 0;
}
