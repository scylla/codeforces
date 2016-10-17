#include <bits/stdc++.h>
#define cs ios::sync_with_stdio(false);
using namespace std;

class TreeNode
{
public:
	int count;
	long long int suff;
	vector< TreeNode* > children;
	TreeNode()
	{
		suff = 0;
		count = 0;
		children.assign(2,NULL);
	}
};

int max_bits = 40;
TreeNode* root = new TreeNode();

void TreeInsertOperation(long long int suf)
{
	TreeNode* temp = root;
	for(int i = max_bits; i>0; i--)
	{
		bool b = (suf & (1LL << (i - 1)));
		if(!temp->children[b])
			temp->children[b] = new TreeNode();
		temp->children[b]->count++;
		temp = temp->children[b];
	}
	temp->suff = suf;
}

void TreeRemoveOperation(long long int suf)
{
	TreeNode* temp = root;
	for(int i = max_bits; i>0; i--)
	{
		bool b = (suf & (1LL << (i - 1)));
		temp->children[b]->count--;
		temp = temp->children[b];
	}
}

long long int PerformXOR(long long int pre)
{
	TreeNode* temp = root;
	for(int i = max_bits; i>0; i--)
	{
		bool b = (pre & (1LL << (i - 1)));
		b = !b;
		if(!temp->children[b] || temp->children[b]->count==0)
			b = !b;
		temp = temp->children[b];
	}
	return (pre ^ temp->suff);
}

int main()
{
	cs
	int n;
	cin>>n;
	long long int ar[n], ans;
	for(int i=0;i<n;i++)
		cin>>ar[i];
	long long int suf[n], pre = ar[0];
	ans = suf[n-1] = ar[n-1];
	for(int i=n-2;i>=0;i--)
	{
		suf[i] = suf[i+1]^ar[i];
		ans = max(suf[i] , ans);
	}
	for(int i=1;i<n;i++)
		TreeInsertOperation(suf[i]);
	for(int i=0;i<n-1;i++)
	{
		ans = max(ans, max(pre, PerformXOR(pre)));
		TreeRemoveOperation(suf[i+1]);
		pre = pre^ar[i+1];
	}
	ans = max(pre, ans);
	cout<<ans;
}