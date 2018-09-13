//
//  bitwise-ors-of-subarrays
//  https://leetcode.com/problems/bitwise-ors-of-subarrays/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // 设st1表示以A[i-1]结尾的子段的ORs集合，st2表示以A[i]结尾的子段的ORs集合
        // st2等于 {A[i] | st1中的各个元素} + {A[i]}
        unordered_set<int> st1, st2, ans;
        for (int num : A) {
            st2 = { num };
            for (int x : st1) st2.insert(num | x);
            st1 = st2;
            ans.insert(st2.begin(), st2.end());
        }
        return ans.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
