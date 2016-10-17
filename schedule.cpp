// https://www.hackerrank.com/challenges/square-subsequences

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
#define pb push_back

using namespace std;

typedef pair<int, int> pii;
typedef pair<int, pii> piii;
typedef vector<piii> store;

bool customCompare(piii& p1, piii& p2) {
    return p1.F < p2.F;
}

bool hotel(vector<int> &arrive, vector<int> &depart, int K) {
    int n = arrive.size();
    vector<bool> vis(n, false);
    store data;
    for(int i = 0; i < n; ++i) { // 1 arrival 2 departure
        data.pb(mp(arrive[i], mp(i, 1)));
        data.pb(mp(depart[i], mp(i, 2)));
    }
    sort(data.begin(), data.end(), customCompare);
    int active = 0;
    bool feasible = true;
    for(int i = 0; i < data.size(); ++i) {
        piii cur = data[i];
        if(cur.S.S == 1) {
            active++;
            vis[cur.S.F] = true;
        } else {
            active--;
        }
        if(active > K) {
            feasible = false;
            break;
        }
    }

    if(feasible) return true;
    else return false;
}

int main() {
    return 0;
}