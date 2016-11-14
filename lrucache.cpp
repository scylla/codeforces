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
#include <unordered_map>

struct Lnode {
  Lnode(int dd) {
      data = dd;
  }
  Lnode* pre;
  Lnode* nxt;
  int data;
};

class LRUCache{
public:
    unordered_map<int, Lnode*> cache;
    Lnode* head;
    Lnode* tail;
    int size;
    int cap;
    LRUCache(int capacity) {
        cap = capacity;
        size = 0;
    }

    int get(int key) {
        if(cache.find(key) != cache.end()) {
            cout << "get " << key << endl;
            return key;
        } else  {
            cout << "get " << -1 << endl;
            return -1;
        }
    }

    void set(int key, int value) {
        cout << "set " << key << endl;
        if(size == cap) {
            if(cache.find(key) != cache.end()) {
                Lnode* cur = cache[key];
                if(cur != tail) {
                    cache.erase(key);
                    cur->pre->nxt = cur->nxt;
                    cur->nxt->pre = cur->pre;
                    cur->nxt = NULL;
                    cur->pre = tail;
                    tail = cur;
                    cache[key] = tail;
                }
            } else {
                cache.erase(head->data);
                head->nxt->pre = NULL;
                Lnode* temp = head;
                head = head->nxt;
                delete temp;
                Lnode* node = new Lnode(key);
                tail->nxt = node;
                node->pre = tail;
                tail = node;
                cache[key] = tail;
            }
        } else {
            if(size == 0) {
                Lnode* head = new Lnode(key);
                cache[key] = head;
                size++;
            } else {
                if(cache.find(key) != cache.end()) {
                    Lnode* cur = cache[key];
                    if(cur != tail) {
                        cache.erase(key);
                        cur->pre->nxt = cur->nxt;
                        cur->nxt->pre = cur->pre;
                        cur->nxt = NULL;
                        cur->pre = tail;
                        tail = cur;
                        cache[key] = tail;
                    }
                } else {
                    Lnode* node = new Lnode(key);
                    tail->nxt = node;
                    node->pre = tail;
                    tail = node;
                    cache[key] = tail;
                    size++;
                }
            }
        }
    }
};

int main() {
    int n,m;
    cin >> n >> m;
    LRUCache lc(n);
    for(int i = 0; i < m; ++i) {
        char tp;
        int x;
        cin >> tp >> x;
        if(tp == 's') {
            lc.set(x);
        } else {
            lc.get(x);
        }
    }
    return 0;
}