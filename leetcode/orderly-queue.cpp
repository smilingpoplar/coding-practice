//
//  orderly-queue
//  https://leetcode.com/problems/orderly-queue/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string orderlyQueue(string S, int K) {
        // 当K>1时，每次从前K个数中选最小的放到队尾，做完一轮逆序数减少
        // 实际上是用K长窗口做了一遍冒泡排序，最终将排好序
        if (K > 1) {
            sort(S.begin(), S.end());
            return S;
        }
        // K==1时，从循环串中找最小的
        const int N = S.size();
        string SS = S + S;
        string ans = S;
        for (int i = 1; i < N; i++) {
            ans = min(ans, SS.substr(i, N));
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
