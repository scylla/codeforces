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
#define setzero(A) memset((A), 0, sizeof (A))
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

typedef vector<pair<string, int>> vsi;

const int MOD = 1e9 + 7;
ll INF = 1e15 + 7;
int INT_INF = 1e9 + 9;
const int NMAX = 1002;

class graph
{
	public:
	int n;
	list<pii> *a;
	graph(int n)
	{
		this->n = n;
		a = new list<pii>[n];
	}

    void addEdge(int u, int v, int w)
    {
        a[u].push_back(mp(v,w));
        a[v].push_back(mp(u,w));
    }

    int solve()
    {
        priority_queue<pii, vector<pii>, greater<pii> > pq;
        int src = 0;
        vector<int> key(n,INT_MAX);
        vector<int> parent(n,-1);
        vector<bool> ok(n,false);
        pq.push(mp(0,src));
        key[src] = 0;
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            if(ok[u])
                continue;
            ok[u] = true;
            list<pair<int,int> >::iterator i;
            for(i = a[u].begin();i!=a[u].end();++i)
            {
                int v = (*i).first;
                int wt = (*i).second;
                if(ok[v]==false && key[v]>wt)
                {
                    key[v] = wt;
                    pq.push(mp(key[v],v));
                    parent[v] = u;
                }
            }
        }
        ll sum = 0;
        for(auto item : key) {
        	sum += item;
        }
        return sum;
    }
};

int main()
{
	int n,m;
	cin>>n>>m;
	graph adjgraph(n);
	for(int i=0;i<m;i++)
	{
		int u , v, w;
		cin >> u >> v >> w;
		if(w == 0)
		{
         adjgraph.addEdge(u-1,v-1,0);
		}
		else
		{
            int w;
            cin>>w;
            adjgraph.addEdge(u-1,v-1,w);
		}
	}
	cout<< adjgraph.solve() << endl;
}
