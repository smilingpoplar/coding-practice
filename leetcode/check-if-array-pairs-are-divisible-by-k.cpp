//
//  check-if-array-pairs-are-divisible-by-k
//  https://leetcode.com/problems/check-if-array-pairs-are-divisible-by-k/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        // 数组中两两之和能否被k整除？
        // 先把数组中数%k处理一遍，然后(a+b)%k=0，a%k=(k-b)%k
        unordered_map<int, int> cnt; // num=>count
        for (int num : arr) {
            num %= k;
            if (num < 0) num += k;
            cnt[num]++;
        }
        
        if (cnt[0] % 2 != 0) return false;
        for (int i = 1; i <= k / 2; i++) {
            if (cnt[i] != cnt[k-i]) return false;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
