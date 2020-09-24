//
//  majority-element
//  https://leetcode.com/problems/majority-element/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cand = INT_MIN;
        int cnt = 0;
        for (int num : nums) {
            if (num == cand) {
                cnt++;
            } else if (cnt == 0) {
                cand = num;
                cnt++;
            } else {
                cnt--;
            }
        }
        return cand;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {6,5,5};
    Solution solution;
    cout << solution.majorityElement(nums);
 
    return 0;
}
