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
#define fast_io ios_base::sync_with_stdio(0); cin.tie(0); // using purely c++ iostreams so avoid syncing with c iostreams

using namespace std;
typedef long long ll;

vector<int> groupCount; // number of elements in each group
map<int, vector<bool>> groupMap; // all blocks in a group true if a block is in the same group false otherwise
int lastGroup; // to track lastly created group

inline bool isPartitioned(int K) {
	cout << "partitioned " << lastGroup << " | " << K << endl;
	return lastGroup + 1 == K;
}

void updateGroups(vector<string>& blocks, int checkBit, int K) {
	cout << "check bit " << checkBit << " K " << K << " -- " << lastGroup << endl;
	int lastGroupId = lastGroup;
	for(int grpIdx = 0; grpIdx <= lastGroupId; ++grpIdx) {
		if(groupCount[grpIdx] < 2) continue;
		cout << "lastGroup " << lastGroup << endl;
		bool grpUpdated = false;
		for(int blkIdx = 0; blkIdx < K; ++blkIdx) {
			// update group of elements for which bit is zero
			if(groupMap[grpIdx][blkIdx] && blocks[blkIdx][checkBit] == '0') {
					groupCount[grpIdx]--;
					groupMap[grpIdx][blkIdx] = false;
					groupCount[lastGroup+1] += 1;
					groupMap[lastGroup+1][blkIdx] = true;
					grpUpdated = true;
			}
		}
		if(grpUpdated) lastGroup++;
		if(lastGroup + 1 == K) break;
	}
	cout << "groups updated exiting .. last group is now " << lastGroup << endl;
}

void printItemsPerGrp(int K, int bsize) {
	cout << "------------------- items ---------------------------- " << endl;
	for(int i = 0; i < K; ++i) {
		int citem = 0;
		for(int j = 0; j < bsize; ++j) {
			if(groupMap[i][j]) citem++;
		}
		cout << citem << endl;
	}
	cout << "------------------- end ---------------------------- " << endl;
}

int getMinBits(vector<string>& blocks, int K) {

	int minBits = 0;
	int numBits = blocks[0].size();
	vector<bool> usedBits(numBits, false); // bits used till now for partition
	vector<int> bitEntropy(numBits); // entropy for current bit
	cout << "in getminbits " << numBits << endl;

	while(!isPartitioned(K)) {

		printItemsPerGrp(K, K);
		int nextBit = -1;
		int maxChange = 0;
		fill(bitEntropy.begin(), bitEntropy.end(), 0);

		for(int grpIdx = 0; grpIdx < K; ++grpIdx) {

			if(groupCount[grpIdx] > 1) {

				cout << "active group " << grpIdx << " num elements " << groupCount[grpIdx] << endl;

				//if(grpIdx == 1) return 100;

				vector<int> grpEntropy(numBits, 0); // add count of ones

				for(int blkIdx = 0; blkIdx < K; ++blkIdx) {
					cout << "grp -- block " << grpIdx << " || " << blkIdx << " -- " << groupMap[grpIdx][blkIdx] << endl;
					if(groupMap[grpIdx][blkIdx]) {
						for(int bitIdx = 0; bitIdx < numBits; ++bitIdx) {
							grpEntropy[bitIdx] += (blocks[blkIdx][bitIdx] - '0');
							//cout << "entropy " << grpEntropy[bitIdx] << endl;
						}
					}
				}

				// update current entropy
				for(int bitIdx = 0; bitIdx < numBits; ++bitIdx) {
					bitEntropy[bitIdx] = min(grpEntropy[bitIdx], groupCount[grpIdx] - grpEntropy[bitIdx]);
					//cout << "entropy updated " << bitEntropy[bitIdx] << endl;
				}

			}
		}


		// get best bit for partition
		for(int bitIdx = 0; bitIdx < numBits; ++bitIdx) {
			if(!usedBits[bitIdx]) {
				if(maxChange < bitEntropy[bitIdx]) {
					maxChange = bitEntropy[bitIdx];
					nextBit = bitIdx;
				}
			}
		}

		//if(nextBit == -1) return 2000;
		cout << "next bit to set " << nextBit << endl;
		// update bits used
		usedBits[nextBit] = true;
		updateGroups(blocks, nextBit, K);
		printItemsPerGrp(K, K);
		//return -1000;
	}
	cout << "bits set " << endl;
	for(int idx = 0; idx < numBits; ++idx) {
		if(usedBits[idx])  {
			minBits++;
			cout << idx << " ";
		}
	}
	cout << "--------------------------" << endl;
	return minBits;
}

int main() {
	fast_io
	int N, M, K;
	cin >> N >> M >> K;
	cout << N << " " << M << " " << K << endl;
	vector<string> blocks(K);
	groupCount.resize(K, 0);
	// initialize group map
	for(int idx = 0; idx < K; ++idx) {
		vector<bool> zeroGroupMembers;
		if(idx == 0) {
			zeroGroupMembers.resize(K, true);
			groupCount[idx] = K;
		} else {
			groupCount[idx] = 0;
			zeroGroupMembers.resize(K, false);
		}
		groupMap[idx] = zeroGroupMembers;
	}
	for(int idx = 0; idx < K; ++idx) {
		string str;
		for(int rowidx = 0; rowidx < N; ++rowidx) {
			cin >> str;
			blocks[idx] += str; // each row combined into a single string
		}
		cout << "input " << idx << " " << blocks[idx] << endl;
	}
	cout << getMinBits(blocks, K) << endl;
	return 0;
}