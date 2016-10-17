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
const int NMAX = 210;
double dp[NMAX][NMAX];
char str[NMAX];


int main() {
	int n;
	cin >> n;
	vi bsizes;
	int csize = 0;
	char ch;
	for(int i = 0; i < n; ++i) {
		cin >> ch;
		if(ch == 'B')
			csize++;
		else {
			if(csize > 0)
				bsizes.eb(csize);
			csize = 0;
		}
	}
	if(csize > 0)
		bsizes.eb(csize);
	cout << bsizes.size() << endl;
	if(bsizes.size() > 0) {
		for(auto it : bsizes) {
			cout << it << " ";
		}
		cout << endl;
	}
	return 0;
}