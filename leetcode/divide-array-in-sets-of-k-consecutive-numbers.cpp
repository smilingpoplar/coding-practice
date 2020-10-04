//
//  divide-array-in-sets-of-k-consecutive-numbers
//  https://leetcode.com/problems/divide-array-in-sets-of-k-consecutive-numbers/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if (nums.size() % k != 0) return false;
        map<int, int> cnt; // num=>count
        for (int num : nums) {
            cnt[num]++;
        }
        
        for (auto [num, count] : cnt) {
            if (count > 0) { // [num..num+k)都减count
                for (int i = 0; i < k; i++) {
                    cnt[num + i] -= count;
                    if (cnt[num + i] < 0) return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
