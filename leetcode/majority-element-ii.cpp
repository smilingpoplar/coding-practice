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
        // 一般化，找出现次数大于n/k的元素（最多k-1个，这里k==3）
        // 找候选的过程：每次删掉k个不同的元素
        unordered_map<int, int> count;
        for (auto num : nums) {
            ++count[num];
            if (count.size() == 3) { // 每次删掉k个不同的元素
                auto it = count.begin();
                while (it != count.end()) {
                    --it->second;
                    if (it->second == 0) {
                        it = count.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }
        // 验证候选
        for (auto &kv : count) {
            kv.second = 0;
        }
        for (auto num : nums) {
            if (count.find(num) != count.end()) {
                ++count[num];
            }
        }
        vector<int> result;
        for (const auto &kv : count) {
            if (kv.second > nums.size() / 3) {
                result.push_back(kv.first);
            }
        }
        return result;
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
