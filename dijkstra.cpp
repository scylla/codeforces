#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>

#define F first
#define S second
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
const int INF = 1e9 + 7;

struct comp {
  bool operator()(const pii& p1, const pii& p2) {
    return p1.S < p2.S;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  for(int t = 0; t < T; ++t) {
    int N, M;
    cin >> N >> M;
    vector<vector<pii>> graph(N);
    for(int m = 0; m < M; ++m) {
      int x, y, r;
      cin >> x >> y >> r;
      graph[x-1].pb({r, y-1});
      graph[y-1].pb({r, x-1});
    }
    vector<int> costs(N, INF);
    int S;
    cin >> S;
    costs[S-1] = 0;
    set<pii> sd;
    sd.insert({0, S-1});
    while(!sd.empty()) {
      pii fr = *(sd.begin());
      int u = fr.S;
      sd.erase(sd.begin());
      for(pii it : graph[u]) {
        int v = it.S;
        int wt = it.F;
        if(costs[v] > costs[u] + wt) {
          if(costs[v] != INF) {
            sd.erase(sd.find({costs[v], v}));
          }
          costs[v] = costs[u] + wt;
          sd.insert({costs[v], v});
        }
      }
    }

    for(int l = 0; l < N; ++l) {
      if(l != S-1) {
        if(costs[l] != INF)
          cout << costs[l] << " ";
        else cout << -1 << " ";
      }
    }
    cout << endl;
  }
    return 0;
}