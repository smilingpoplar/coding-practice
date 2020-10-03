//
//  merge-intervals
//  https://leetcode.com/problems/merge-intervals/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return {};
        sort(begin(intervals), end(intervals));
        
        vector<vector<int>> ans;
        for (auto &interval : intervals) {
            if (ans.empty() || interval[0] > ans.back()[1]) {
                ans.push_back(interval);
            } else {
                ans.back()[1] = max(ans.back()[1], interval[1]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
