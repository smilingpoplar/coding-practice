//
//  3sum
//  https://leetcode.com/problems/3sum/
//
//  Created by smilingpoplar on 15/5/10.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        const int N = (int)nums.size();
        if (N < 3) return result;
        sort(nums.begin(), nums.end()); // 先排序再两端夹逼
        
        for (int first = 0; first < N - 2; ++first) {
            while (0 < first && first < N - 2 && nums[first] == nums[first - 1]) ++first;
            int second = first + 1;
            int third = N - 1;
            int target = 0;
            while (second < third) {
                int sum  = nums[first] + nums[second] + nums[third];
                if (sum == target) {
                    result.push_back({nums[first], nums[second], nums[third]});
                    ++second;
                    while (second < third && nums[second] == nums[second - 1]) ++second;
                    --third;
                    while (second < third && nums[third] == nums[third + 1]) --third;
                } else if (sum < target) {
                    ++second;
                    while (second < third && nums[second] == nums[second - 1]) ++second;
                } else {
                    --third;
                    while (second < third && nums[third] == nums[third + 1]) --third;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    auto result = solution.threeSum(nums);
    for (const auto &threeNums : result) {
        for (int num: threeNums) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
