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
const int NMAX = 100001;
bool visited[NMAX];
bool printed;
void printPath(vi& kpath) {
    printed = true;
    for(auto it = kpath.begin(); it != kpath.end(); ++it) {
        cout << *it << " ";
    }
    cout << "\n";
}
void dfs(vvi& graph, vi& kpath, int start, int& plen) {
    visited[start] = true;
    plen--;
    int vidx = kpath.size();
    kpath.eb(start);
    if(plen == 0)
        printPath(kpath);
    else {
        for(auto it = graph[start].begin(); it != graph[start].end(); ++it) {
            if(!visited[*it])
                dfs(graph, kpath, *it, plen);
            if(printed)
                return;
        }
        kpath.erase(kpath.begin()+vidx, kpath.end());
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while(T--) {
        int N, K;   
        cin >> N >> K;
        vvi graph(N+1);
        memset(visited, 0, sizeof visited);
        printed = false;
        for(int  i = 0; i < N-1; ++i) {
            int x, y;
            cin >> x >> y;
            graph[x].eb(y);
            graph[y].eb(x);
        }
        for(int i = 1; i <= N; ++i) {
            sort(graph[i].begin(), graph[i].end());
        }
        int U = ceil((K-1)*1.0/N);
        int X = K - (U-1)*N;
        vi kpath;
        dfs(graph, kpath, U, X);
    }
    return 0;
}

