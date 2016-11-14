#include <iostream>
#include <map>
#include <vector>
using namespace std;
///////////////////////////SubMain//////////////////////////////////
class CCustomer
{
public:
	int types;
	map<int, int> malt;
	bool satisfied;
	bool isLike(int flavor, int malted)
	{
		map<int,int>::iterator it = malt.find(flavor);
		if (it != malt.end())
		{
			if (it->second == malted)
			{
				return true;
			}
			else
			{
				return false;
			}
		}

		return false;
	}

	bool isSatisfied(const vector<int>& flavors)
	{
		for (int i = 0; i < flavors.size(); i++)
		{
			if (isLike(i + 1, flavors[i]))
			{
				return true;
			}
		}
		return false;
	}

	int countMalted()
	{
		int m = 0;
		for (map<int, int>::iterator it = malt.begin(); it != malt.end(); it++)
		{
			if (it->second == 1)
			{
				m++;
			}
		}

		return m;
	}
};
int main(int argc, char *argv[])
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int nCases = 0;
	cin >> nCases;
	cin.get();
	for (int i = 0; i < nCases; i++)
	{
		cout << "Case #" << i + 1 << ": ";
		int flavors = 0;
		cin >> flavors;
		vector<int> milkshakes;
		vector<CCustomer> allCustomers;
		int customers = 0;
		cin >> customers;
		for (int j = 0; j < customers; j++)
		{
			CCustomer c;
			cin >> c.types;
			for (int k = 0; k < c.types; k++)
			{
				int x = 0;
				int y = 0;
				cin >> x;
				cin >> y;
				c.malt[x] = y;
				c.satisfied = false;
			}
			allCustomers.push_back(c);
		}

		for (int j = 0; j < flavors; j++)
		{
			int n = 0;
			milkshakes.push_back(n);
		}

		for (int j = 0; j < customers; j++)
		{
			CCustomer c = allCustomers[j];
			if (!c.isSatisfied(milkshakes))
			{
				if (c.countMalted() == 0)
				{
					// 客户只喜欢unmalted
					bool all_malted = true;
					for (map<int, int>::iterator it = c.malt.begin(); it != c.malt.end(); it++)
					{
						if (milkshakes[it->first - 1] != 1)
						{
							all_malted = false;
							break;
						}
					}
					if (all_malted)
					{
						customers = -1;				 // 用-1表示这个case无解
						break;
					}
				}

				if (customers >= 0)
				{
					for (map<int, int>::iterator it = c.malt.begin(); it != c.malt.end(); it++)
					{
						if (it->second == 1)
						{
							milkshakes[it->first - 1] = 1;
							j = -1;
							break;
						}
					}
				}
			}
		}


		if (customers < 0)
		{
			cout << "IMPOSSIBLE" << endl;
		}
		else
		{
			for (int j = 0; j < flavors; j++)
			{
				cout << milkshakes[j] << " ";
			}
			cout << endl;
		}
	}
	//fclose(stdin);
	//fclose(stdout);
	return 0;
}
///////////////////////////End Sub//////////////////////////////////
