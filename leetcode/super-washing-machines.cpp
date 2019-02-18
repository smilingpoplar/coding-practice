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

        // 一次move相当于给机器添一单位流量的管道，各机器要能保证通过：
        // 1. 自己能发出流量：out[i] = machines[i]-avg，
        //    不用abs(out[i])？比如[-1 2 -1]要两次，[1 -2 1]只需一次，用abs(out[i])就错了。
        // 2. 通过它流向另一侧的流量：abs(sum(out[0..i]))。sum为正向右流、为负向左流。
        int avg = sum / N;
        int toRight = 0;
        int ans = 0;
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
