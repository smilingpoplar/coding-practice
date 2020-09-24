//
//  relative-sort-array
//  https://leetcode.com/problems/relative-sort-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 计数排序
        map<int, int> cnt; // num=>count
        for (int num : arr1) {
            cnt[num]++;
        }
        int i = 0;
        for (int num : arr2) {
            while (cnt[num]-- > 0) {
                arr1[i++] = num;
            }
        }
        for (auto &e : cnt) {
            while (e.second-- > 0) {
                arr1[i++] = e.first;
            }
        }
        return arr1;
    }
};

/*
class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        // 在arr2中的数按照rank[x]来排
        unordered_map<int, int> rank; // value=>rank
        for (int i = 0; i < arr2.size(); i++) {
            rank[arr2[i]] = i;
        }
        // 不在arr2中的数按照x+1000来排
        sort(arr1.begin(), arr1.end(), [&rank](int a, int b){
            int aIdx = rank.count(a) ? rank[a] : a + 1000;
            int bIdx = rank.count(b) ? rank[b] : b + 1000;
            return aIdx < bIdx;
        });
        return arr1;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
