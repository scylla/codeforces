#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <vector>

using namespace std;

string solve(string str) {
	stack<int> pos_stk[26];
	vector<bool> vis(26, false);
	vector<int> last_pos(26, -1);
	int sz = str.size();
	for(int i = sz - 1; i >= 0; --i) {
		pos_stk[str[i]-'a'].push(i);
		if(last_pos[str[i]-'a'] == -1) last_pos[str[i]-'a'] = i;
	}
	string res;
	for(int i = 0; i < sz; ++i) {
		int cur = str[i] - 'a';
		if(vis[cur]) continue;
		if(pos_stk[cur].size() == 1) {
			res += str[i];
			pos_stk[cur].pop();
			vis[cur] = true;
			continue;
		}
		int min_pos = sz;
		for(int j = 0; j < 26; ++j) {
			if(!vis[j] && !pos_stk[j].empty()) {
				min_pos = min(min_pos, last_pos[j]);
			}
		}
		bool is_smaller = false;
		for(int k = 0; k < cur && !is_smaller; ++k) {
			if(vis[k] || pos_stk[k].empty()) continue;
			if(pos_stk[k].top() < min_pos) is_smaller = true;
		}
		if(!is_smaller) {
			res += str[i];
			vis[cur] = true;
		}
		pos_stk[cur].pop();
	}
	return res;
}

int main() {
	string str;
	cin >> str;
	cout << solve(str) << endl;
	return 0;
}