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
        // 假设无法绕圈，则存在某一站的消耗 cost(i)-gas(i) > 其他站的总积累 sum( gas(j)-cost(i) )，
        // 即所有站的 sum( gas(i)-cost(i) ) < 0，所以只要 sum( gas(i)-cost(i) ) >=0 总能绕一圈。
        // 在绕圈的过程中每站剩余汽油 left >= 0
        const int N = (int)gas.size();
        int sum = 0;
        int left = 0;
        int start = 0;
        for (int i = 0; i < N; i++) {
            int gasI = gas[i] - cost[i];
            sum += gasI;
            left += gasI;
            if (left < 0) {
                start = i + 1; // 尝试从下一站开始
                left = 0;
            }
        }
        if (sum < 0) return -1;
        return start; // sum >= 0 总能绕一圈
    }
};

int main(int argc, const char * argv[]) {
    vector<int> gas = {4, 3};
    vector<int> cost = {5, 2};
    Solution solution;
    cout << solution.canCompleteCircuit(gas, cost);
    
    return 0;
}
