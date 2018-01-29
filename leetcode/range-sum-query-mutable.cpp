//
//  range-sum-query-mutable
//  https://leetcode.com/problems/range-sum-query-mutable/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class NumArray {
    vector<int> t;
    int n;
public:
    NumArray(vector<int> nums) {
        // 用线段树作动态范围查询
        n = nums.size();
        t = vector<int>(2*n);
        // build
        for (int i = n; i < 2*n; i++) {
            t[i] = nums[i-n];
        }
        for (int i = n - 1; i >= 1; i--) {
            t[i] = t[2*i] + t[2*i+1];
        }
    }
    
    void update(int i, int val) {
        i += n;
        t[i] = val;
        for (int j = i/2; j >= 1; j /= 2) {
            t[j] = t[2*j] + t[2*j+1];
        }
    }
    
    int sumRange(int i, int j) {
        int sum = 0;
        for (i += n, j += n; i <= j; i /= 2, j /= 2) {
            if (i % 2 == 1) sum += t[i++];
            if (j % 2 == 0) sum += t[j--];
        }
        return sum;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
