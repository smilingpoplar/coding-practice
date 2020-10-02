//
//  find-a-value-of-a-mysterious-function-closest-to-target
//  https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        // func(arr,l,r)做范围与操作
        // 在set[r]中保存所有arr[l]~arr[r],l<=r的“范围与”结果，
        // set[r+1] = { set[r]中各数 & arr[r+1], arr[r+1] }
        unordered_set<int> set;
        int ans = INT_MAX;
        for (int a : arr) {
            unordered_set<int> next;
            next.insert(a);
            for (auto x : set) {
                next.insert(x & a);
            }
            for (auto x : next) {
                ans = min(ans, abs(x - target));
            }
            swap(set, next);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
