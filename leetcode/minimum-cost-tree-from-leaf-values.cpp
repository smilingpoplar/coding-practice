//
//  minimum-cost-tree-from-leaf-values
//  https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int> &arr) {
        // 题目：数组对应叶节点值的中序遍历，内节点代价=左右子树最大叶节点之积，
        //      总代价=内节点代价之和，求所有树结构中的最小总代价。
        // 转换：每次从两个邻居节点a和b中删除min(a,b)，代价为a*b，
        //      求所有删除顺序中代价最小的。
        // 每次删除局部最小值（波谷）
        int ans = 0;
        stack<int> stk;
        stk.push(INT_MAX);  // 左哨兵
        for (int val : arr) {
            while (!stk.empty() && val > stk.top()) {
                int localMin = stk.top();
                stk.pop();
                ans += localMin * min(stk.top(), val);
            }
            stk.push(val);
        }
        // 递减栈，栈顶是最小值
        while (stk.size() > 2) {
            int localMin = stk.top();
            stk.pop();
            ans += localMin * stk.top();
        }
        return ans;
    }
};

int main(int argc, const char *argv[]) {
    return 0;
}
