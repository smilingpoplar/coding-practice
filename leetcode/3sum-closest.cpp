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
        
        int minDist = INT_MAX;
        int ans;
        for (int a = 0; a < N - 2; a++) {
            int b = a + 1, c = N - 1;
            while (b < c) {
                int sum  = nums[a] + nums[b] + nums[c];
                int dist = abs(sum - target);
                if (dist < minDist) {
                    minDist = dist;
                    ans = sum;
                }
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    b++;
                } else {
                    c--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(nums, target);
    
    return 0;
}
