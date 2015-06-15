//
//  rectangle-area
//  https://leetcode.com/problems/rectangle-area/
//
//  Created by smilingpoplar on 15/6/15.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int area = (C - A) * (D - B) + (G - E) * (H - F);
        if (E >= C || A >= G || B >= H || F >= D) return area;
        return area - (min(C, G) - max(A, E)) * (min(D, H) - max(B, F)); // 相交矩形的右左上下
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.computeArea(0, 0, 0, 0, -1, -1, 1, 1);

    return 0;
}
