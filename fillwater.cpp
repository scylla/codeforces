#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#include <set>
#include <map>
#include <stack>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); // using purely c++ iostreams so avoid syncing with c iostreams

using namespace std;

int main() {
    vector<int> A;
    int N;
    cin >> N;
    A.resize(N, 0);
    for(int i = 0; i < N; ++i) {
        cin >> A[i];
    }
    stack<int> stk;
    int res = 0;
    int idx = 0;
    int lh = -1;
    while(idx < A.size()) {
        if(A[idx] == 0) {
            idx++;
            continue;
        }
        if(stk.empty()) {
            stk.push(idx);
            lh = -1;
            idx++;
        } else if(A[idx] < A[stk.top()]) {
            stk.push(idx);
            lh = -1;
            idx++;
        } else {

            int tp = stk.top();
            stk.pop();
            if(lh == -1) {
                cout << "cal " << A[tp] << " -- " << idx - tp - 1 << endl;
                res += A[tp]*(idx - tp - 1);
            } else {
                cout << "cal " << (A[tp] - lh) << " -- " << idx - tp - 1 << endl;
                res += (A[tp] - lh)*(idx - tp - 1);
            }
            if(stk.empty()) lh = -1;
            else lh = A[tp];

        }
        cout << idx << " || " << lh << " -- " << res << endl;
    }
    cout << res << endl;
    return 0;
}