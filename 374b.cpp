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

typedef vector<pair<string, int>> vsi;

const int MOD = 1e9 + 7;
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int NMAX = 210;
double dp[NMAX][NMAX];
char str[NMAX];

bool compareData(pair<string, int> p1, pair<string, int> p2) {
	return p1.S < p2.S;
}

int main() {
	vsi data;
	int n, k;
	string pass;
	cin >> n >> k;
	string temp;
	for(int i = 0; i < n; ++i) {
		cin >> temp;
		data.eb(mp(temp, temp.size()));
	}
	cin >> pass;
	int pln = pass.size();
	sort(data.begin(), data.end(), compareData);
	int wlen = 0, blen = 0;
	int slen = 0;
	for(auto item : data) {
		if(item.S < pln) blen++;
		if(item.S == pln) slen++;
	}
	// cout << blen << " " << slen << endl;
	int bout = blen + (blen/k)*5 + 1;
	int wout = blen + slen + ((blen + slen - 1)/k)*5;
	cout << bout << " " << wout << endl;
	return 0;
}
