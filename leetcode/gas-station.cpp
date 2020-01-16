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
        // 只要 sum(gas[i]-cost[i]) >=0 就能绕圈
        // 因为若无法绕圈，存在某站的消耗 cost[i]-gas[i] > 其他站的总积累 sum(gas[j]-cost[j])，
        // 所有站的总积累 sum(gas[i]-cost[i]) < 0 ==取逆否命题=> sum(gas[i]-cost[i]) >=0 就能绕圈

        const int N = gas.size();
        int start = 0;
        int gasSum = 0, gasFromStart = 0;
        for (int i = 0; i < N; i++) {
            int gasI = gas[i] - cost[i];
            gasSum += gasI, gasFromStart += gasI;
            if (gasFromStart < 0) { // i站及前面站不能作为起点，下一站作起点候选
                start = i + 1;
                gasFromStart = 0;
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
