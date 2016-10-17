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

int repeatedNumber(const vector<int> &A) {
 int n = A.size();
 if(n < 3) {
     return A[0];
 }
 if(n <= 5) {
     map<int, int> cmap;
     for(int i = 0; i < n; ++i) {
         if(cmap.find(A[i]) != cmap.end()) {
             cmap[A[i]]++;
             if(cmap[A[i]] == 2) return A[i];
         } else {
             cmap[A[i]] = 1;
         }
     }
     return -1;
 }
 int k = A.size()/3;
 int cap = 2;
 map<int, int> n3c;
 for(int i = 0; i < A.size(); ++i) {
     if(n3c.find(A[i]) != n3c.end()) {
         n3c[A[i]]++;
     } else {
         if(n3c.size() < cap) {
             n3c[A[i]] = 1;
         } else {
            if(n3c.size() == cap) {
             for(const pair<int, int>& it : n3c) {
                 n3c[it.first]--;
                 if(n3c[it.first] == 0) n3c.erase(it.first);
             }
            }
         }
     }
 }

 for(auto it : n3c) {
     n3c[it.first] = 0;
 }

 for(int i = 0; i < A.size(); ++i) {
     if(n3c.find(A[i]) != n3c.end()) {
         n3c[A[i]]++;
         if(n3c[A[i]] > k) {
             return A[i];
         }
     }
 }

  return -1;
}

int main() {
    int n;
    cin >> n;
    vector<int> data(n);
    for(int i = 0; i < n; ++i) {
        cin >> data[i];
    }
    cout << "res " << repeatedNumber(data) << endl;
    return 0;
}