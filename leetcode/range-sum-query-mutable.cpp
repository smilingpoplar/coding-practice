//
//  range-sum-query-mutable
//  https://leetcode.com/problems/range-sum-query-mutable/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/*
class NumArray {
    class FenwickTree {
        static inline int lowbit(int x) { return x & -x; }
        vector<int> _sums;
    public:
        // 1-based，在_sums[1..n]保存部分和
        FenwickTree(int n): _sums(n + 1, 0) { }

        void update(int idx, int delta) {
            while (idx < _sums.size()) {
                _sums[idx] += delta;
                idx += lowbit(idx);
            }
        }
        // 返回sum[1..idx]
        int query(int idx) const {
            int sum = 0;
            while (idx) {
                sum += _sums[idx];
                idx -= lowbit(idx);
            }
            return sum;
        }
    };
    
    vector<int> _nums;
    FenwickTree _tree;
public:
    NumArray(vector<int>& nums) 
        : _nums(nums), _tree(nums.size()) {
        for (int i = 0; i < _nums.size(); i++) {
            _tree.update(i + 1, _nums[i]);
        }
    }
    
    void update(int i, int val) {
        _tree.update(i + 1, val - _nums[i]);
        _nums[i] = val;
    }
    
    int sumRange(int i, int j) {
        return _tree.query(j + 1) - _tree.query(i);
    }
};
*/

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
