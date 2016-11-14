#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    for (string line; getline(cin, line);) {

        cout << line << endl;
        vector<int> a1;
        vector<int> a2;
        int temp = 0;
        int idx;

        for(idx = 0; idx < line.size(); ++idx) {
        	char ch = line[idx];
        	if(ch == ' ') {
        		a1.push_back(temp);
        		temp = 0;
        	} else if(ch == '#') {
        		a1.push_back(temp);
        		temp = 0;
        		break;
        	} else {
        		temp = temp*10 + (ch-'0');
        	}
        }

        for(idx = idx+1; idx < line.size(); ++idx) {
        	char ch = line[idx];
        	if(ch == ' ') {
        		a2.push_back(temp);
        		temp = 0;
        	} else {
        		temp = temp*10 + (ch-'0');
        	}
        }

        a2.push_back(temp);

        for(int i = 0; i < a1.size(); ++i) {
        	cout << a1[i] << " ";
        }
        cout << endl;
        for(int i = 0; i < a2.size(); ++i) {
        	cout << a2[i] << " ";
        }
        cout << endl;
    }
    return 0;
}