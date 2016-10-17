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
const int NMAX = 1002;

int main() {
	int type;

	cin >> type;
	string s;
	cin >> s;

	int mm = (s[4] - '0') + 10*(s[3] - '0');
	int hh = (s[1] - '0') + 10*(s[0] - '0');

	if(type == 12) {
		if(hh > 12 || hh < 1) {
			cout << "0" << ((hh % 10) != 0 ? hh % 10: 1) << ":";
		} else cout << hh << ":";
		if(mm > 59) {
			cout << "0" << mm % 10 << endl;
		} else cout << mm << endl;
	} else {
		if(hh > 23) {
			cout << "0" << hh % 10 << ":";
		} else cout << hh << ":";
		if(mm > 59) {
			cout << "0" << mm % 10 << endl;
		} else cout << mm << endl;
	}
	return 0;
}

