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
        // 区间按end排序，end相同的优先考虑范围小的
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });
        int ans = 0;
        int last2 = INT_MIN, last1 = INT_MIN; // 要创建的集合S的最后两个数
        for (auto &interval : intervals) {
            if (last1 < interval[0]) { // 当前区间与S不相交，往S中加入当前区间的最后两个数
                ans += 2;
                last1 = interval[1];
                last2 = last1 - 1;
            } else if (last2 < interval[0] && interval[0] <= last1) { // 往S中加入当前区间的最后一个数
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
