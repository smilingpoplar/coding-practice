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
        unordered_set<int> set1;
        int ans = INT_MAX;
        for (int a : arr) {
            unordered_set<int> set2;
            set2.insert(a);
            for (auto x : set1) {
                set2.insert(x & a);
            }
            for (auto x : set2) {
                ans = min(ans, abs(x - target));
            }
            swap(set1, set2);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
