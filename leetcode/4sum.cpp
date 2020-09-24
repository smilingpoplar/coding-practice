//
//  4sum
//  https://leetcode.com/problems/4sum/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        const int N = nums.size();
        if (N < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for (int ia = 0; ia < N - 3; ia++) {
            while (0 < ia && ia < N - 3 && nums[ia] == nums[ia-1]) ia++;
            for (int ib = ia + 1; ib < N - 2; ib++) {
                while (ia + 1 < ib && ib < N - 2 && nums[ib] == nums[ib-1]) ib++;
                int ic = ib + 1, id = N - 1;
                while (ic < id) {
                    int sum = nums[ia] + nums[ib] + nums[ic] + nums[id];
                    if (sum == target) {
                        ans.push_back({nums[ia], nums[ib], nums[ic], nums[id]});
                        ic++;
                        while (ic < id && nums[ic] == nums[ic-1]) ic++;
                        id--;
                        while (ic < id && nums[id] == nums[id+1]) id--;
                    } else if (sum < target) {
                        ic++;
                        while (ic < id && nums[ic] == nums[ic-1]) ic++;
                    } else {
                        id--;
                        while (ic < id && nums[id] == nums[id+1]) id--;
                    }
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    Solution solution;
    auto ans = solution.fourSum(nums, target);
    for (const auto &quad : ans) {
        for (auto num : quad) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
