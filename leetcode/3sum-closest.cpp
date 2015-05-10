//
//  3sum-closest
//  https://leetcode.com/problems/3sum-closest/
//
//  Created by smilingpoplar on 15/5/10.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = (int)nums.size();
        // assert(N >= 3);
        sort(nums.begin(), nums.end()); // 先排序再两端夹逼
        
        int minDistance = INT_MAX;
        int result;
        for (int first = 0; first < N - 2; ++first) {
            int second = first + 1;
            int third = N - 1;
            while (second < third) {
                int sum  = nums[first] + nums[second] + nums[third];
                int distance = abs(sum - target);
                if (distance < minDistance) {
                    minDistance = distance;
                    result = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    ++second;
                } else {
                    --third;
                }
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(nums, target);
    
    return 0;
}
