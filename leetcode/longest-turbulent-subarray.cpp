//
//  longest-turbulent-subarray
//  https://leetcode.com/problems/longest-turbulent-subarray/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.empty()) return 0;
        int up = 1, down = 1, ans = 1;
        for (int i = 1; i < A.size(); i++) {
            if (A[i] > A[i-1]) {
                up = down + 1;
                down = 1;
            } else if (A[i] < A[i-1]) {
                down = up + 1;
                up = 1;
            } else {
                up = down = 1;
            }
            ans = max({ans, up, down});
        }
        return ans;
    }
};

/*
class Solution {
public:
    int maxTurbulenceSize(vector<int>& A) {
        if (A.empty()) return 0;
        int len = 1, ans = 1;
        int prevDiff = 0;
        for (int i = 1; i < A.size(); i++) {
            int diff = A[i] - A[i-1];
            if ((diff > 0 && prevDiff <= 0) || (diff < 0 && prevDiff >= 0)) {
                len++;
            } else {
                len = diff == 0 ? 1 : 2;
            }
            ans = max(ans, len);
            prevDiff = diff;
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
