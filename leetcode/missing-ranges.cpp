//
//  missing-ranges
//  https://leetcode.com/problems/missing-ranges/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ans;
        long from = lower; // 缺失区间的起点
        for (long num : nums) {
            if (num < lower || num > upper) continue;
            if (num > from) ans.push_back(rangeStr(from, num - 1));
            from = num + 1;
        }
        if (upper >= from) ans.push_back(rangeStr(from, upper));
        return ans;
    }
    
    string rangeStr(int from, int to) {
        if (from == to) return to_string(from);
        return to_string(from) + "->" + to_string(to);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
