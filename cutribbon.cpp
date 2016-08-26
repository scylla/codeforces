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
#define NMAX 4001

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

int arr[NMAX];
using namespace std;

int main() {
	int n, a, b, c;
	cin >> n >> a >> b >> c;
	memset(arr, -1, sizeof arr);
	arr[0] = 0;
	for(int i = 1; i <= n; ++i) {
		if(i-a >= 0 && arr[i-a] != -1) 
			arr[i] = max(arr[i], 1 + arr[i-a]);
		if(i-b >= 0 && arr[i-b] != -1)
			arr[i] = max(arr[i], 1 + arr[i-b]);
		if(i-c >= 0 && arr[i-c] != -1)
			arr[i] = max(arr[i], 1 + arr[i-c]);
	}
	cout << arr[n] << endl;
	return 0;
}