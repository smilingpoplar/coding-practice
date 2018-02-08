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
        for (int load : machines)
            sum += load;
        if (sum % N != 0) return -1;

        int avg = sum / N;
        // 各机器除了看自己有多少衣服要走：out[i]=machines[i]-avg。
        // 还要看左边和右边有多少衣服要通过它另一边。已知所有out[i]和为0，经移动后要全成0。
        // machines[i]有sum(out[i..N-1])要通过它往左，有sum(out[0..i])要通过它往右。
        int ans = 0;
        int toRight = 0;
        for (int i = 0; i < N; i++) {
            int out = machines[i] - avg;
            toRight += out; // sum(out[0..i])
            int toLeft = out - toRight; // sum(out[i..N-1])
            ans = max({ans, out, toLeft, toRight});
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
