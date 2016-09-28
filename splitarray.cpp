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
const int NMAX = 5e5 + 5;
int arr[16385];
ll sums[16385];

int result;

int bsearch(ll val, int low, int high) {
	int mid;
	// cout << "searching " << val << "  " << low << " | " << high << endl;
	while(low < high) {
		mid = (low + high) / 2;
		// cout << "mid " << mid << endl;
		if(sums[mid] == val) {
			return mid;
		}
		if(sums[mid] > val) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	if(sums[high] == val)
		return high;
	else return -1;
}

void solve(int start, int end, ll sum) {
	if(start >= end) {
		return;
	}
	// cout << "solve " << start << " " << end << endl;
	int div = bsearch(sum + sums[start-1], start, end);
	if(div != -1) {
		result++;
		ll tsum = sum/2;
		if(sum & 1) return;
		else {
			if(sum > 0) {
				solve(start, div, tsum);
				solve(div+1, end, tsum);
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		int N;
		cin >> N;
		result = 0;
		bool iszero = true;
		memset(arr, 0, sizeof arr);
		memset(sums, 0, sizeof sums);
		for(int i = 1; i <= N; ++i) {
			cin >> arr[i];
			sums[i] += sums[i-1] + arr[i];
			cout << sums[i] << " ";
			if(arr[i] != 0)
				iszero = false;
		}
		cout << endl;
		if(iszero)
			cout << N-1 << endl;
		else {
			if(sums[N] & 1)
				cout << 0 << endl;
			else {
				solve(1, N, sums[N]/2);
				cout << "result " << result << endl;
			}
		}
	}
	return 0;
}