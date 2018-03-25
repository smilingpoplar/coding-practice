//
//  find-the-celebrity
//  https://leetcode.com/problems/find-the-celebrity/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// Forward declaration of the knows API.
bool knows(int a, int b);

class Solution {
public:
    int findCelebrity(int n) {
        // 名人：他不知道其他人、其他人知道他
        int candidate = 0;
        for (int i = 1; i < n; i++) {
            if (knows(candidate, i)) { // candidate知道i，candidate不可能是名人
                candidate = i;
            }
        }
        // 至此，candidate=k：[0..k-1]知道其他人，不是名人；k不知道[k+1,n-1]，[k+1,n-1]不是名人；k是唯一候选
        // 下面验证k是不是真名人，已知"k不知道[k+1,n-1]"（不用再验证）
        for (int i = 0; i < candidate; i++) {
            if (!knows(i, candidate) || knows(candidate, i)) return -1;
        }
        for (int i = candidate + 1; i < n; i++) {
            if (!knows(i, candidate)) return -1;
        }
        return candidate;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
