//
//  k-closest-points-to-origin
//  https://leetcode.com/problems/k-closest-points-to-origin/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        partial_sort(points.begin(), points.begin() + K, points.end(), [](vector<int> &a, vector<int> &b) {
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        });
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};

/*
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        auto cmp = [&points](int i, int j) { // 最大堆
            auto &a = points[i], &b = points[j];
            return (a[0] * a[0] + a[1] * a[1]) < (b[0] * b[0] + b[1] * b[1]);
        }; 
        priority_queue<int, vector<int>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < points.size(); i++) {
            pq.push(i);
            if (i >= K) pq.pop();
        }
        
        vector<vector<int>> ans;
        while (!pq.empty()) {
            ans.push_back(points[pq.top()]);
            pq.pop();
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
