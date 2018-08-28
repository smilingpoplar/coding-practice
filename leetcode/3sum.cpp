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
        sort(nums.begin(), nums.end()); // 先排序再两指针

        vector<vector<int>> ans;        
        for (int ia = 0; ia < N - 2; ia++) {
            while (0 < ia && ia < N - 2 && nums[ia] == nums[ia-1]) ia++; // 去重，相同数字只取第一个
            int ib = ia + 1, ic = N - 1, target = 0;
            while (ib < ic) {
                int sum  = nums[ia] + nums[ib] + nums[ic];
                if (sum == target) {
                    ans.push_back({nums[ia], nums[ib], nums[ic]});
                    ib++;
                    while (ib < ic && nums[ib] == nums[ib-1]) ib++;
                    ic--;
                    while (ib < ic && nums[ic] == nums[ic+1]) ic--;
                } else if (sum < target) {
                    ib++;
                    while (ib < ic && nums[ib] == nums[ib-1]) ib++;
                } else {
                    ic--;
                    while (ib < ic && nums[ic] == nums[ic+1]) ic--;
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
