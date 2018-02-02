//
//  top-k-frequent-elements
//  https://leetcode.com/problems/top-k-frequent-elements/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;
        for (int num : nums) {
            count[num]++;
        }
        // 相同频率放一个桶
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &e : count) {
            buckets[e.second].push_back(e.first);
        }
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0 && ans.size() < k; i--) {
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) break;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
