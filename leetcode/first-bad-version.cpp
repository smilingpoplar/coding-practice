//
//  first-bad-version
//  https://leetcode.com/problems/first-bad-version/
//
//  Created by smilingpoplar on 17/10/12.
//  Copyright (c) 2017年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    // 二分搜索，[0,...,0,1,1,..]找第一个1
    // x[l]<t<=x[h]，l+1=h是x[h]是要找的数
    int firstBadVersion(int n) {
        int l = 0;
        int h = n + 1;
        while (l + 1 < h) {
            int mid = l + (h - l) / 2;
            if (isBadVersion(mid)) {
                h = mid;
            } else {
                l = mid;
            }
        }
        if (isBadVersion(h)) return h;
        return INT_MAX;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
