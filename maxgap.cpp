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
#define pb push_back

using namespace std;

int maximumGap(const vector<int> &A) {
   int n = A.size();
   if(n < 2) return -1;
   if(n == 2) return A[1];
   int sqn = sqrt(n-1);
   vector<int> sqblocks(sqn + 1, 0);
   int fblock = -1;
   int blast = sqn;
   int cplast = n-1 - sqn*sqn;
   for(int i = 0; i < n; ++i) {
       int temp = A[i]-1;
       sqblocks[temp/sqn]++;
       if(temp/sqn != blast && sqblocks[temp/sqn] > sqn) {
           fblock = temp/sqn;
           break;
       }
       if(temp/sqn == blast && sqblocks[temp/sqn] > cplast) {
            fblock = temp/sqn;
            break;
       }
   }

   set<int> vis;

   int rep = -1;
   cout << "sqn " << sqn << " || fblock " << fblock << endl;

   if(fblock != -1) {
    for(int i = 0; i < n; ++i) {
       cout << i << endl;
       int temp = A[i]-1;
       if(temp/sqn == fblock) {
           if(!vis.empty() && vis.find(A[i]) != vis.end()) {
               rep = A[i];
               break;
           } else vis.insert(A[i]);
       }
    }
   }
   return rep;
}

int main() {
    int n;
    cin >> n;
    vector<int> data;
    while(n--) {
        int item;
        cin >> item;
        data.push_back(item);
    }
    cout << maximumGap(data) << endl;
    return 0;
}
