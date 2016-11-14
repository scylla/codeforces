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
	int n;
	cin >> n;
	int max_len = 0;
	int inpar = 0;
	bool ispar = false;
	char ch;
	int cursize;
	for(int i = 0; i < n; ++i) {
		cin >> ch;
		if(ch == '(') {
			ispar = true;
			if(cursize > 0) {
				max_len = max(max_len, cursize);
				cursize = 0;
			}
		} else if(ch == ')') {
			ispar = false;
			if(cursize > 0) {
				inpar++;
				cursize = 0;
			}
		} else if(ch == '_') {
			if(cursize > 0) {
				if(ispar) inpar++;
				else max_len = max(max_len, cursize);
				cursize = 0;
			}
		} else {
			cursize++;
			if(!ispar)
				max_len = max(max_len, cursize);
		}
	}
	cout << max_len << " " << inpar << endl;
	return 0;
}