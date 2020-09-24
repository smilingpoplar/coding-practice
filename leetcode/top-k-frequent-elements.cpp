//
//  top-k-frequent-elements
//  https://leetcode.com/problems/top-k-frequent-elements/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> cnt;
        for (int num : nums) cnt[num]++;
        // 相同频率放一个桶
        vector<vector<int>> buckets(nums.size() + 1);
        for (auto &e : cnt) 
            buckets[e.second].push_back(e.first);
        
        vector<int> ans;
        for (int i = buckets.size() - 1; i >= 0; i--) {
            if (buckets[i].empty()) continue;
            for (int num : buckets[i]) {
                ans.push_back(num);
                if (ans.size() == k) return ans;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
