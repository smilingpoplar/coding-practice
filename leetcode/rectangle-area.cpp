//
//  rectangle-area
//  https://leetcode.com/problems/rectangle-area/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area1 = (C - A) * (D - B), area2 = (G - E) * (H - F);
        if (E >= C || A >= G || B >= H || F >= D) return area1 + area2;
        int overlap = (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)); // 相交部分的右左上下
        return area1 - overlap + area2;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.computeArea(0, 0, 0, 0, -1, -1, 1, 1);

    return 0;
}
