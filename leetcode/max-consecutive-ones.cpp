//
//  max-consecutive-ones
//  https://leetcode.com/problems/max-consecutive-ones/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int ones = 0, ans = 0;
        for (int num : nums) {
            if (num == 1) {
                ones++;
                ans = max(ans, ones);
            } else {
                ones = 0;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
