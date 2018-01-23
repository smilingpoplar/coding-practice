//
//  set-intersection-size-at-least-two
//  https://leetcode.com/problems/set-intersection-size-at-least-two/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 区间按end排序，end相同的先取范围小的
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        // 每个区间中最多取最后连续两个
        int last2 = INT_MIN, last1 = INT_MIN;
        for (auto &interval : intervals) {
            if (last1 < interval[0]) { // 取最后两个
                ans += 2;
                last2 = interval[1] - 1;
                last1 = interval[1];
            } else if (last2 < interval[0] && interval[0] <= last1) { // 取最后一个
                ans += 1;
                last2 = last1;
                last1 = interval[1];
            }
        }
        return ans;
    }
};


int main(int argc, const char * argv[]) {    
    return 0;
}
