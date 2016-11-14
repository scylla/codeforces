#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <algorithm>
#include <utility>
#include <map>
#define F first
#define S second

using namespace std;

stack<pair<int, int>> topo;

void dfs(int node, int pr, vector<vector<int>>& graph, vector<bool>& vis) {
	vis[node] = true;
	for(auto x : graph[node]) {
		if(!vis[x]) {
			dfs(x, node, graph, vis);
		}
	}
	cout << "adding " << node << " " << pr << endl;
	topo.push({node, pr});
	// cout << topo.size() << endl;
}

int main() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n+1);
	vector<vector<int>> prs(n+1);
	for(int i = 1; i <= n ; ++i) {
		int cc;
		cin >> cc;
		for(int j = 0; j < cc; ++j) {
			int el;
			cin >> el;
			graph[i].push_back(el);
			prs[el].push_back(i);
		}
	}
	vector<bool> vis(n+1, false);
	for(int i = 1; i <= n; ++i) {
		if(!vis[i]) {
			dfs(i, -1, graph, vis);
		}
	}
	map<int, int> idmap;
	int cv = 1;
	while(!topo.empty()) {
		pair<int, int> item = topo.top();
		if(item.S == -1) {
			if(prs[item.F].size()) {
				int mv = INT_MIN;

			}
		}
		topo.pop();
	}
	cout << endl;
	return 0;
}