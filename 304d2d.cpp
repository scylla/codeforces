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
const ll INF = 1e15 + 7;
const int NMAX = 5e6 + 5;
int counts[NMAX];
int primes[NMAX];
int sums[NMAX];

int main(){
    for(int i = 0; i < NMAX; ++i) {
        counts[i] = i;
    }
    int sqrtn = sqrt(NMAX);
    for(int i = 2; i <= sqrtn; ++i) {
        if(counts[i] == i)
            for(int j = i*i; j < NMAX; j += i) {
                if(counts[j] == j)
                    counts[j] = i;
            }
    }
    for(int i = 2; i < NMAX; ++i) {
        primes[i] = primes[i/counts[i]] + 1;
    }
    for(int i = 2; i < NMAX-1 ; ++i) {
        sums[i] = sums[i-1] + primes[i];
    }
    int t;
    scanf("%d",&t);
    while(t--) {
        int a, b;
        scanf("%d%d",&a,&b);
        printf("%d\n",sums[a]-sums[b]);
    }
    return 0;
}

