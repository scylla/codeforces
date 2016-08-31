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
#define mp(a, b) make_pair(a,b)
#define F first
#define S second
#define NMAX 100001

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int arr[NMAX];
using namespace std;

int main() {
	string s;
	cin >> s;	
	for(int i = 1; i < s.size(); ++i) {
		if(s.at(i) == s.at(i-1))
			arr[i] += 1 + arr[i-1];
		else arr[i] = arr[i-1];
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; ++i) {
		int l, r;
		cin >> l >> r;
		if(r-1 >= l-1)
			cout << arr[r-1] - arr[l-1] << endl;
		else cout << 0 << endl;

	}
	return 0;
}