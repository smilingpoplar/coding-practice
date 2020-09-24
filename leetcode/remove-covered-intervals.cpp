//
//  remove-covered-intervals
//  https://leetcode.com/problems/remove-covered-intervals/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        // 按起点正序、终点逆序排
        sort(intervals.begin(), intervals.end(), 
             [](vector<int> &a, vector<int> &b){
            if (a[0] == b[0] && a[1] > b[1]) return true;
            return a[0] < b[0];
        });
        int end = INT_MIN, ans = 0;
        for (auto &cur : intervals) {
            if (cur[1] > end) {
                ans++;
                end = cur[1];
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
