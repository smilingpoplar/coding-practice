//
//  di-string-match
//  https://leetcode.com/problems/di-string-match/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> diStringMatch(string S) {
        // 遇'I'输出最小值lo（下一值肯定更大），
        // 遇'D'输出最大值hi（下一值肯定更小）。
        vector<int> ans;
        int lo = 0, hi = S.size();
        for (char c : S) {
            ans.push_back(c == 'I' ? lo++ : hi--);
        }
        ans.push_back(lo);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
