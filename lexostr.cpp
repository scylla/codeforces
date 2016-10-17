#include <algorithm>
#include <iostream>
#include <cstring>
#include <utility>
#include <vector>
#include <queue>
#define F first
#define S second
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0);
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long int ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vii;
typedef pair<long, long> pll;

const int NMAX = 1002;
int arr[NMAX];

void solve(int n, int k) {
	int pos;
	for(int i = 1; i <= n; ++i) {
		pos = i;
		for(int j = i + 1; j <= n; ++j) {
			if(j-i > k) break;
			if(arr[j] < arr[pos]) pos = j;
		}
		for(int j = pos; j > i; --j) {
			arr[j]=(arr[j]+arr[j-1])-(arr[j-1] = arr[j]);
		}
		k -= pos - i;
	}
	for(int i = 1;i <= n; ++i)
		cout << arr[i] << " ";
		cout << endl;
}

int main() {
	int T;
	cin >> T;
	while(T--) {
		int n, k;
		cin >> n >> k;
		for(int i = 1; i <= n; ++i) {
			cin >> arr[i];
		}
		solve(n, k);
	}
	return 0;
}