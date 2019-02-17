//
//  partition-labels
//  https://leetcode.com/problems/partition-labels/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
        int left = 0, right = -1;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, lastIdx[S[i]]);
            if (i == right) { // 右端点不再扩展时子段结束
                ans.push_back(right - left + 1);
                left = right + 1;
            }
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
