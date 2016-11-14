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

using namespace std;

int main() {
	vector<int> arr(3, 0);
	cin >> arr[0] >> arr[1] >> arr[2];
	sort(arr.begin(), arr.end());
	cout << arr[1] - arr[0] + arr[2] - arr[1] << endl;
	return 0;
}