//
//  gas-station
//  https://leetcode.com/problems/gas-station/
//
//  Created by smilingpoplar on 15/5/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        // 若无法绕圈时，存在某一站的消耗 cost(i)-gas(i) > 其他站的总积累 sum( gas(j)-cost(j) )，
        // 所有站的积累 sum( gas(i)-cost(i) ) < 0。取逆否命题：sum( gas(i)-cost(i) ) >=0 就能绕圈。
        // 
        // 只要 gasSum>=0 就能绕圈。
        // 若到某站gasLeft<0，则该站及前面站不能作起点，下一站作候选起点。
        const int N = gas.size();
        int gasSum = 0, gasLeft = 0;
        int start = 0;
        for (int i = 0; i < N; i++) {
            int gasI = gas[i] - cost[i];
            gasSum += gasI, gasLeft += gasI;
            if (gasLeft < 0) {
                start = i + 1; // 下一站作候选起点
                gasLeft = 0;
            }
        }
        if (gasSum < 0) return -1;
        return start;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> gas = {4, 3};
    vector<int> cost = {5, 2};
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost);
    
    return 0;
}
