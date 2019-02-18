//
//  bag-of-tokens
//  https://leetcode.com/problems/bag-of-tokens/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        // token有两种用法：-tokens[i]、+1分，+tokens[i]、-1分
        // 贪婪法，尽量多加分少减分，让单位token加分最多减分最少。
        // 加分时用最小的tokens[i]、减分时用最大的tokens[i]
        sort(tokens.begin(), tokens.end());
        int i = 0, j = (int)tokens.size() - 1;
        int point = 0, ans = 0;
        while (i <= j) {
            if (P >= tokens[i]) {
                P -= tokens[i++];
                ans = max(ans, ++point);
            } else if (point > 0) {
                P += tokens[j--];
                point--;
            } else {
                break;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
