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
#define NMAX 500005

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;
int arr[NMAX];
int ctr[NMAX];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	ll sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		sum += arr[i];
	}
	if(sum%3 != 0) {
		cout << 0 << endl;
	} else {
		sum /= 3;
		ll s = 0;
		for(int i = n-1; i >= 0; --i) {
			s += arr[i];
			if(s == sum)
				ctr[i] = 1;
		}
		for(int i = n-2; i >= 0; --i) {
			ctr[i] += ctr[i+1];
		}
		ll ans = 0;
		s = 0;
		for(int i = 0; i+2 < n; ++i) {
			s += arr[i];
			if(s == sum){
				ans += ctr[i+2];
			} 
		}
		cout << ans << endl;
	}
	return 0;
}