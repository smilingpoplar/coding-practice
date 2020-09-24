//
//  swap-adjacent-in-lr-string
//  https://leetcode.com/problems/swap-adjacent-in-lr-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canTransform(string start, string end) {
        // 把L看作面朝左的人、R看作面朝右的人、X看作空位，那么L朝左走、R朝右走、且不能越过别人
        // 1. 比较start串和end串除了X外的LR序列是否相同
        // 2. end串的相应L要在start串的L的左边（朝左走）、end串的相应R要在start串的R的右边（朝右走）
        const int M = start.size(), N = end.size();
        int i = 0, j = 0;
        while (true) {
            while (i < M && start[i] == 'X') i++;
            while (j < N && end[j] == 'X') j++;
            if (i == M && j == N) return true;
            if (i == M || j == N) return false;
            if (start[i] != end[j]) return false;
            if (start[i] == 'L' && j > i) return false;
            if (start[i] == 'R' && j < i) return false;
            i++;
            j++;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
