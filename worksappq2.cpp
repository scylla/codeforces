#include <vector>
#include <iomanip>
#include <iostream>
#include <cstdio>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <algorithm>
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); // using purely c++ iostreams so avoid syncing with c iostreams

using namespace std;
typedef long long ll;

const int BIT_SIZE = 40; // max 40 bits are needed to store numbers of size 10^12

vector<ll> inputArray;
vector<ll> xorSuffix;

ll result;

struct TrieNode {
	TrieNode* parent; // used for parent node
	TrieNode* zeroPointer; // used for bit 0
	TrieNode* onePointer; // used for bit 1
	int count; // count to decide node validity not applicable for root
	TrieNode(TrieNode* parPtr, TrieNode* zeroPtr, TrieNode* onePtr) {
		parent = parPtr;
		zeroPointer = zeroPtr;
		onePointer = onePtr;
		count = 0;
	}
};

// pre-calculate xor of suffixes for input array elements [1..arraySize]
void processSuffixes(int arraySize) {
	xorSuffix.resize(arraySize, 0);
	xorSuffix[arraySize - 1] = inputArray[arraySize - 1];
	result = max(result, xorSuffix[arraySize - 1]);
	for(int index = arraySize - 2; index >= 1; --index) {
		xorSuffix[index] = xorSuffix[index + 1]^inputArray[index];
		result = max(result, xorSuffix[index]); // update result simultaneously
	}
}

// build suffix trie using suffix values from 1..arraySize
void buildSuffixTrie(TrieNode* trieRoot, int arraySize) {
	for(int index = 1; index <= arraySize - 1; ++index) {
		TrieNode* temp = trieRoot;
		for(int bitIndex = BIT_SIZE; bitIndex >= 0; --bitIndex) {
			int currentBit = (xorSuffix[index] >> bitIndex) & 1l; // just considering one bit at a time
			if(currentBit == 0) {
				if(temp->zeroPointer == NULL) {
					temp->zeroPointer = new TrieNode(temp, NULL, NULL);
				}
				temp = temp->zeroPointer;
				temp->count += 1;
			} else {
				if(temp->onePointer == NULL) {
					temp->onePointer = new TrieNode(temp, NULL, NULL);
				}
				temp = temp->onePointer;
				temp->count += 1;
			}
		}
	}
}

// deletes a value from suffix trie
void deleteFromSuffixTrie(TrieNode* trieRoot, ll value) {
	TrieNode* temp = trieRoot;
	for(int bitIndex = BIT_SIZE; bitIndex >= 0; --bitIndex) {
		int currentBit = (value >> bitIndex) & 1l;
		if(currentBit == 0) {
			temp = temp->zeroPointer;
			temp->count -= 1;
			if(temp->count == 0) {
				temp->parent->zeroPointer = NULL;
				delete temp;
				return;
			}
		} else {
			temp = temp->onePointer;
			temp->count -= 1;
			if(temp->count == 0) {
				temp->parent->onePointer = NULL;
				delete temp;
				return;
			}
		}
	}
}

ll queryTrie(TrieNode* trieRoot, ll value) {
	ll queryResult = 0l;
	TrieNode* temp = trieRoot;
	for(int bitIndex = BIT_SIZE; bitIndex >= 0; --bitIndex) {
		int currentBit = (value >> bitIndex) & 1l;
		if(currentBit == 0) {
			if(temp->onePointer != NULL) {
				queryResult |= (1l << bitIndex);
				temp = temp->onePointer;
			} else temp = temp->zeroPointer;
		} else {
			if(temp->zeroPointer != NULL) {
				queryResult |= (1l << bitIndex);
				temp = temp->zeroPointer;
			} else temp = temp->onePointer;
		}
	}
	return queryResult;
}

// just a test function
void printTrie(TrieNode* trieRoot) {
	while(trieRoot != NULL) {
		cout << trieRoot->count << " ";
		trieRoot = trieRoot->zeroPointer;
	}
	cout << endl;
}

int main() {
	fast_io
	int arraySize;
	cin >> arraySize;
	inputArray.resize(arraySize, 0);
	result = 0;
	for(int index = 0; index < arraySize; ++index) {
		cin >> inputArray[index];
	}
	processSuffixes(arraySize);
	TrieNode* trieRoot = new TrieNode(NULL, NULL, NULL);
	trieRoot->count = -1;
	buildSuffixTrie(trieRoot, arraySize);
	ll curPrefix = 0l;
	ll queryResult;
	for(int index = 0; index <= arraySize - 2; ++index) {
		curPrefix ^= inputArray[index];
		result = max(result, curPrefix);
		queryResult = queryTrie(trieRoot, curPrefix);
		result = max(result, queryResult);
		deleteFromSuffixTrie(trieRoot, xorSuffix[index+1]);
	}
	cout << result << endl;
	return 0;
}
