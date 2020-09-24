//
//  super-washing-machines
//  https://leetcode.com/problems/super-washing-machines/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMinMoves(vector<int>& machines) {
        const int N = machines.size();
        int total = 0;
        for (int machine : machines)
            total += machine;
        if (total % N != 0) return -1;

        // 每个洗衣机要发出衣服：out[i] = machines[i]-avg
        // 1. 一次只能发一件，发out[i]件需要out[i]次
        // 2. 通过本机发向另一侧的件数 x=abs(sum(out[0..i]))，
        //    sum为正向右流、为负向左流，又需要x次
        int avg = total / N;
        int sum = 0;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            int out = machines[i] - avg;
            sum += out; // sum(out[0..i])
            ans = max({ans, out, abs(sum)});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
