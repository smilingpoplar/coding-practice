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
        vector<int> _nums;
        vector<int> _tree; // 使用_tree[1..n]
    public:
        FenwickTree(const vector<int> &nums)
            : _nums(nums.size()), _tree(nums.size() + 1) { 
            for (int i = 0; i < _nums.size(); i++) {
                update(i, nums[i]);
            }
        }

        void update(int i, int val) {
            int delta = val - _nums[i];
            _nums[i] = val;
            i++;
            while (i < _tree.size()) {
                _tree[i] += delta;
                i += lowbit(i);
            }
        }

        // 返回_nums[0..i]的和
        int presum(int i) const {
            i++;
            int sum = 0;
            while (i) {
                sum += _tree[i];
                i -= lowbit(i);
            }
            return sum;
        }
    };
    
    FenwickTree _tree;
public:
    NumArray(vector<int>& nums) : _tree(nums) { }
    
    void update(int i, int val) {
        _tree.update(i, val);
    }
    
    int sumRange(int i, int j) {
        return _tree.presum(j) - _tree.presum(i - 1);
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
