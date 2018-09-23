//
//  super-washing-machines
//  https://leetcode.com/problems/super-washing-machines/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        const int N = machines.size();
        int sum = 0;
        for (int machine : machines)
            sum += machine;
        if (sum % N != 0) return -1;

        int avg = sum / N;
        // 想象洗衣机是节点，一次move就是连接一条1单位粗的管道
        // 各机器除了要自己能发出流量：out[i] = machines[i]-avg
        // 还要保证从一侧（含自己）通过它的流量：abs(sum(out[0..i]))，sum为正时向右流、为负时向左流
        int ans = 0;
        int toRight = 0;
        for (int i = 0; i < N; i++) {
            int out = machines[i] - avg;
            toRight += out; // sum(out[0..i])
            ans = max({ans, out, abs(toRight)});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
