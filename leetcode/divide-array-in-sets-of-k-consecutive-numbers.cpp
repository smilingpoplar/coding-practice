//
//  divide-array-in-sets-of-k-consecutive-numbers
//  https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        map<int, int> cnt; // num=>count
        for (int num : nums) {
            cnt[num]++;
        }
        
        for (auto &e : cnt) {
            int count = e.second;
            if (count > 0) { // [num..num+W)都减count
                int num = e.first;
                for (int i = 0; i < W; i++) {
                    cnt[num+i] -= count;
                    if (cnt[num+i] < 0) return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
