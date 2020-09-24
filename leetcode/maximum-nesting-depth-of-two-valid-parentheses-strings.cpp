//
//  maximum-nesting-depth-of-two-valid-parentheses-strings
//  https://leetcode.com/problems/maximum-nesting-depth-of-two-valid-parentheses-strings/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        // 括号子序列尽量均匀地分成两组
        const int N = seq.size();
        vector<int> ans(N, 0);
        int depth = 0;
        for (int i = 0; i < N; i++) {
            if (seq[i] == '(') {
                depth++;
                if (depth % 2 == 0) ans[i] = 1;
            } else {
                depth--;
                if (depth % 2 == 1) ans[i] = 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
