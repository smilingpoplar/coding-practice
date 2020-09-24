//
//  first-bad-version
//  https://leetcode.com/problems/first-bad-version/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        // 二分搜索，[0,..,0,1,1,..]找第一个1
        int l = 0, u = n + 1;
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (isBadVersion(mid)) {
                u = mid;
            } else {
                l = mid;
            }
        }
        if (isBadVersion(u)) return u;
        return INT_MAX;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
