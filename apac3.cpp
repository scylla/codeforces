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
#include <unordered_map>
#define mp(a, b) make_pair(a,b)
#define F first
#define S second
#define eb(x) emplace_back(x)
#define set0(A) memset((A), 0, sizeof (A))
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
const ll INF = 1e15 + 7;
const int NMAX = 1e5 + 2;
const int INT_INF = 2*1e9 + 7;

int arr[NMAX];


inline string stringEncode(string str) {
	string res;
	vi alpha(26, 0);
	for(char ch : str) {
		alpha[ch - 'a']++;
	}
	for(int i = 0; i < 26; i++) {
		if(alpha[i] > 0) {
			res += (char)('a' + i) + to_string(alpha[i]);
		}
	}
	//cout << res << endl;
	return res;
}

int solve(unordered_map<string, int>& dict, string s, unordered_map<string, string>& cmap) {

 vector<vector<int>> words(s.length() + 1, vector<int>(0));
 words[s.length()].push_back(1);

 for(int i = s.length() - 1; i >= 0; i--) {
    vector<int> values;
    for(int j = i + 1; j <= s.length(); j++) {
    	string code = cmap[s.substr(i, j - i)];
      if (dict.find(code) != dict.end()) {
          for (int k = 0; k < words[j].size(); k++) {
          	int new_val = ((ll)dict[code]*(ll)words[j][k]) % MOD;
            values.push_back(new_val);
          }
       }
     }
      words[i] = values;
     }
     int result = 0;
     for(int i = 0; i < words[0].size(); ++i) {
     		result = (result + words[0][i]) % MOD;
     }
     return result;

}

int main() {
  fast_io
  int T;
  cin >> T;
  for(int t = 1; t <= T; ++t) {
  	cout << "Case #" << t << ": ";
  	int V, S;
  	cin >> V >> S;
  	unordered_map<string, int> dict;
  	unordered_map<string, string> ciphermap;
  	for(int i = 0; i < V; ++i) {
  		string str;
  		cin >> str;
  		string code = stringEncode(str);
  		if(dict.count(code))
  			dict[code]++;
  		else dict[code] = 1;
  	}
  	for(int i = 0; i < S; ++i) {
  		string snew;
  		cin >> snew;
  		for(int i = snew.length() - 1; i >= 0; i--) {
		    for(int j = i + 1; j <= snew.length(); j++) {
    			string code = stringEncode(snew.substr(i, j - i));
    			ciphermap[snew.substr(i, j - i)] = code;
    		}
    	}
  		int result = solve(dict, snew, ciphermap);
  		cout << result << " ";
  	}
  	cout << endl;
  }
	return 0;
}