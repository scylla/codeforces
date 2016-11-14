#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
	string str;
	cin >> str;
	bool is9s = true;
	for(char ch : str) {
		if(ch != '9') {
			is9s = false;
			break;
		}
	}
	cout << str << endl;
	int n = str.size();
	int lt, rt, mid;
	mid = n/2;
	lt = mid - 1;
	rt = n&1? mid+1: mid;
	while(lt >= 0 && str[lt] == str[rt]) {
		lt--;
		rt++;
	}
	bool ltsmaller = false;
	if(lt < 0 || str[lt] < str[rt]) ltsmaller = true;
	while(lt >= 0) {
		str[rt] = str[lt];
		lt--;
		rt++;
	}
	if(ltsmaller) {
		lt = mid - 1;
		rt = n&1? mid+1: mid;
		int cr = 1;
		if(n&1) {
			int mv = (str[mid] - '0') + cr;
			if(mv >= 10) {
				str[mid] = mv%10 + '0';
			}
			cout << "str mid " << str[mid] << endl;
			cr = mv/10;
		}

		while(lt >= 0) {
			int nv = (str[lt] - '0') + cr;
			cr = nv/10;
			str[lt] = nv%10 + '0';
			str[rt++] = str[lt--];
		}

		if(cr) {
			cout << "1" << str << "1" << endl;
		} else {
			cout << str << endl;
		}
	}
	return 0;
}
