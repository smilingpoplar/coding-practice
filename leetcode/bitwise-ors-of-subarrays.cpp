//
//  bitwise-ors-of-subarrays
//  https://leetcode.com/problems/bitwise-ors-of-subarrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // 用set[r]记录A[l]~A[r]子段的ORs结果
        // set[r+1]为 {set[r]中各数 | A[r+1], A[r+1]}
        unordered_set<int> set1, set2, ans;
        for (int a : A) {
            set2 = {a};
            for (int x : set1) 
                set2.insert(x | a);
            ans.insert(set2.begin(), set2.end());
            swap(set1, set2);
        }
        return ans.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
