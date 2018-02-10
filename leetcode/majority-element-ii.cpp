//
//  majority-element-ii
//  https://leetcode.com/problems/majority-element-ii/
//
//  Created by smilingpoplar on 15/6/29.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        // 一般化，找出现次数>n/k的元素
        // 算法是：每次删掉k个不同的元素，最后剩下的为候选
        unordered_map<int, int> count;
        for (auto num : nums) {
            count[num]++;
            if (count.size() == 3) {
                auto it = count.begin();
                while (it != count.end()) {
                    it->second--;
                    if (it->second == 0) {
                        it = count.erase(it);
                    } else {
                        it++;
                    }
                }
            }
        }
        // 验证候选的出现次数
        for (auto &e : count) {
            e.second = 0; // 准备给候选重新计数
        }
        for (auto num : nums) {
            if (count.find(num) != count.end()) count[num]++;
        }
        vector<int> ans;
        for (const auto &e : count) {
            if (e.second > nums.size() / 3) {
                ans.push_back(e.first);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {0,1,2,0,1};
    Solution solution;
    auto result = solution.majorityElement(nums);
    for (auto num : result) {
        cout << num << " ";
    }
    
    return 0;
}
