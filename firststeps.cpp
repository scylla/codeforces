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
#define NMAX 100001

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;
int arr[NMAX];

int main() {
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
	}
	int best = 1, cur = 1;
	for(int i = 1; i < n; ++i) {
		if(arr[i] >= arr[i-1]) 
			++cur;
		else {
			best = max(best, cur);
			cur = 1;
		}
	}
	cout << max(best, cur) << endl;
	return 0;
}