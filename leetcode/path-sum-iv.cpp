//
//  path-sum-iv
//  https://leetcode.com/problems/path-sum-iv/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int pathSum(vector<int>& nums) {
        if (nums.empty()) return 0;
        // 第一数字表示depth，第二数字表示在它那一层的pos，第三数字表示值val
        // "xy?"前两个数字xy是节点位置信息，它的左子节点是(x+1)(2y-1)?，右子节点是(x+1)(2y)?，可模拟dfs遍历
        unordered_map<int, int> mp; // 用哈希表记录映射：xy=>?
        for (int num : nums)
            mp[num / 10] = num % 10;

        int ans = 0;
        dfs(nums[0] / 10, mp, 0, ans);
        return ans;
    }
    
    void dfs(int xy, unordered_map<int, int> &mp, int sum, int &ans) {
        if (!mp.count(xy)) return;
        sum += mp[xy];
        
        int x = xy / 10, y = xy % 10;
        int left = (x + 1) * 10 + (2 * y - 1), right = left + 1;
        if (!mp.count(left) && !mp.count(right)) { // 叶节点
            ans += sum;
            return;
        }
        dfs(left, mp, sum, ans);
        dfs(right, mp, sum, ans);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
