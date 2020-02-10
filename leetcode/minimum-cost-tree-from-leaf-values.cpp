//
//  minimum-cost-tree-from-leaf-values
//  https://leetcode.com/problems/minimum-cost-tree-from-leaf-values/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int mctFromLeafValues(vector<int>& arr) {
        // 题目：数组对应叶节点值的中序遍历，内节点代价=左右子树最大叶节点之积，
        //      总代价=内节点代价之和，求最小总代价。
        // 每次算完一个内节点，左右子树中较小的叶节点值a以后都不再使用，
        // 只有较大的叶节点值b参与后续的代价计算。要使总代价最小，就要使b最小。
        // 所以对a找下一个更大的数b，对应找波谷（局部最小值），
        // 波谷两侧紧邻是两个方向的下一个更大数，取小者的为b。值a贡献代价a*b。
        int ans = 0;
        stack<int> stk;
        stk.push(INT_MAX); // 左哨兵
        for (int val : arr) {
            while (!stk.empty() && val >= stk.top()) {
                int localMin = stk.top(); stk.pop();
                ans += localMin * min(stk.top(), val);
            }
            stk.push(val);
        }
        // 递减栈，最终要剩2个（左哨兵和根节点）
        while (stk.size() > 2) {
            int localMin = stk.top(); stk.pop();
            ans += localMin * stk.top();
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
