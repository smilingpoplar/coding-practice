//
//  set-intersection-size-at-least-two
//  https://leetcode.com/problems/set-intersection-size-at-least-two/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        // 区间按right排序，right相同时优先考虑范围小的
        sort(intervals.begin(), intervals.end(), [](vector<int> &a, vector<int> &b) {
            if (a[1] == b[1]) return a[0] > b[0];
            return a[1] < b[1];
        });

        int ans = 0;
        // last1,last2是集合S[..last2,last1]的最后两个数
        int last1 = INT_MIN, last2 = INT_MIN;
        for (auto &interval : intervals) {
            if (last1 < interval[0]) {
                // S与当前区间不相交，要在S中加入当前区间的最后两个数
                ans += 2;
                last1 = interval[1];
                last2 = last1 - 1;
            } else if (last2 < interval[0]) {
                // S与当前区间有一个数相交，要在S中加入当前区间的最后一个数
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
