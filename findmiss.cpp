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

void rotate(vvi& A) {
	int n = A.size();
	int T = 0, B = n-1, L = 0, R = n-1;
	int x = n;
	while(T <= B && L <= R) {
		for(int i = 0; i < x-1; ++i) {
			int temp = A[T][L+i];
			A[T][L+i] = A[B-i][L];
			A[B-i][L] = A[B][R-i];
			A[B][R-i] = A[T+i][R];
			A[T+i][R] = temp;
		}
		x = x - 2;
		T++;
		B--;
		L++;
		R--;
	}
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cin >> n;
	vvi A;
	for(int i = 0; i < n; ++i) {
		vi row;
		int x;
		for(int j = 0; j < n; ++j) {
			cin >> x;
			row.push_back(x);
		}
		A.push_back(row);
	}

	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < n; ++j) {
			cout << A[i][j] << " ";
		}
		cout << endl;
	}
	rotate(A);
	return 0;
}