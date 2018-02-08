//
//  longest-consecutive-sequence
//  https://leetcode.com/problems/longest-consecutive-sequence/
//
//  Created by smilingpoplar on 15/6/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        // 把数都塞到集合里，然后取出无x-1的数x看后序的x+1,x+2,...是否也在集合里
        unordered_set<int> set;
        for (int num : nums) 
            set.insert(num);
        
        int longest = 0;
        for (int num : nums) {
            if (set.find(num - 1) != set.end()) continue;
            int length = 1;
            while (set.find(num + length) != set.end())
                length++;
            longest = max(longest, length);
        }
        return longest;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    cout << solution.longestConsecutive(nums);

    return 0;
}
