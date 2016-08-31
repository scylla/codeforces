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
#define NMAX 11

typedef long long ll;
typedef std::pair<ll, ll> pll;
typedef std::pair<int, int> pii;

using namespace std;

int main() {	
	ios::sync_with_stdio(false);
	string s1, s2;
	cin >> s1 >> s2;
	int fp = 0;
	for(char& ch : s1)
		fp += ch == '+'?1:-1;
	int moves = 0, cp = 0;
	for(char& ch : s2)
		if(ch == '?') moves++;
		else cp += ch == '+'?1:-1;
	int dr = abs(fp - cp);
	if((dr+moves)%2 != 0 || moves < dr)
		cout << setprecision(12) << std::fixed << 0.0 << endl;
	else {
		int pmoves = dr + (moves - dr)/2;
		double prob = 1;
		for(int i = moves; i > moves - pmoves; --i)
			prob *= i;
		for(int i = pmoves; i > 1; --i)
			prob /= i;
		prob /= (1 << moves);
		cout << setprecision(12) << prob << endl;
	}
	return 0;
}