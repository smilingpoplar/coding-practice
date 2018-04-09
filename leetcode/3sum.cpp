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
        const int N = nums.size();
        if (N < 3) return {};
        sort(nums.begin(), nums.end()); // 先排序再两端夹逼

        vector<vector<int>> ans;        
        for (int a = 0; a < N - 2; a++) {
            while (0 < a && a < N - 2 && nums[a] == nums[a - 1]) a++;
            int b = a + 1, c = N - 1;
            int target = 0;
            while (b < c) {
                int sum  = nums[a] + nums[b] + nums[c];
                if (sum == target) {
                    ans.push_back({nums[a], nums[b], nums[c]});
                    b++;
                    while (b < c && nums[b] == nums[b - 1]) b++;
                    c--;
                    while (b < c && nums[c] == nums[c + 1]) c--;
                } else if (sum < target) {
                    b++;
                    while (b < c && nums[b] == nums[b - 1]) b++;
                } else {
                    c--;
                    while (b < c && nums[c] == nums[c + 1]) c--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 0, 1, 2, -1, -4};
    Solution solution;
    auto ans = solution.threeSum(nums);
    for (const auto &threeNums : ans) {
        for (int num: threeNums) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
