//
//  majority-element
//  https://leetcode.com/problems/majority-element/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int candidate = INT_MIN;
        int count = 0;
        for (int num : nums) {
            if (count == 0) {
                candidate = num;
                ++count;
            } else if (num == candidate) {
                ++count;
            } else { // 一次删掉k个不同的数
                --count;
            }
        }
        return candidate;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {6,5,5};
    Solution solution;
    cout << solution.majorityElement(nums);
 
    return 0;
}