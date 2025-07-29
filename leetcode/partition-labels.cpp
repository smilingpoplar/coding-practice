//
//  partition-labels
//  https://leetcode.com/problems/partition-labels/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string S) {
        unordered_map<char, int> lastIdx;
        for (int i = 0; i < S.size(); i++) {
            lastIdx[S[i]] = i;
        }

        vector<int> ans;
        // 每个字母都向右扩展当前区间右端点
        int lo = 0, hi = -1;
        for (int i = 0; i < S.size(); i++) {
            hi = max(hi, lastIdx[S[i]]);
            if (i == hi) {  // 右端点不再扩展时子段结束
                ans.push_back(hi - lo + 1);
                lo = hi + 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
