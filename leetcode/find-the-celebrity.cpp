//
//  find-the-celebrity
//  https://leetcode.com/problems/find-the-celebrity/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // 名人：其他人知道他、他不知道其他人
        int cand = 0;
        for (int i = 1; i < n; i++) {
            if (knows(cand, i)) { // cand知道i，cand不是名人
                cand = i;
            }
        }
        // [0..cand)知道其他人，[0..cand)不是名人；
        // [cand+1..n)不被cand知道，[cand+1..n)不是名人；
        // cand是唯一候选。下面验证cand是不是真名人。
        // 已知"cand不知道[cand+1..n)"（不用再验证）
        for (int i = 0; i < cand; i++) {
            if (!knows(i, cand) || knows(cand, i)) return -1;
        }
        for (int i = cand + 1; i < n; i++) {
            if (!knows(i, cand)) return -1;
        }
        return cand;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
