//
//  insert-interval
//  https://leetcode.com/problems/insert-interval/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        // 区间互不重叠、已按起点排序
        vector<vector<int>> before, after; // 前后的不重叠区间
        int left = newInterval[0], right = newInterval[1];
        for (auto& interval : intervals) {
            if (interval[1] < left) before.push_back(interval);
            else if (interval[0] > right) after.push_back(interval);
            else {
                left = min(left, interval[0]);
                right = max(right, interval[1]);
            }
        }

        before.push_back({left, right});
        before.insert(end(before), begin(after), end(after));
        return before;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
