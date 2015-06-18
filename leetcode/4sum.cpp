//
//  4sum
//  https://leetcode.com/problems/4sum/
//
//  Created by smilingpoplar on 15/6/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        const int N = (int)nums.size();
        if (N < 4) return {};
        sort(nums.begin(), nums.end());
        
        vector<vector<int>> result;
        for (int first = 0; first < N - 3; ++first) {
            while (0 < first && first < N - 3 && nums[first] == nums[first - 1]) ++first;
            for (int second = first + 1; second < N - 2; ++second) {
                while (first + 1 < second && second < N - 2 && nums[second] == nums[second - 1]) ++second;
                int third = second + 1;
                int fourth = N - 1;
                while (third < fourth) {
                    int sum = nums[first] + nums[second] + nums[third] + nums[fourth];
                    if (sum == target) {
                        result.push_back({nums[first], nums[second], nums[third], nums[fourth]});
                        ++third;
                        while (third < fourth && nums[third] == nums[third - 1]) ++third;
                        --fourth;
                        while (third < fourth && nums[fourth] == nums[fourth + 1]) --fourth;
                    } else if (sum < target) {
                        ++third;
                        while (third < fourth && nums[third] == nums[third - 1]) ++third;
                    } else {
                        --fourth;
                        while (third < fourth && nums[fourth] == nums[fourth + 1]) --fourth;
                    }
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    auto result = solution.fourSum(nums, target);
    for (const auto &quad : result) {
        for (auto num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}