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
        unordered_map<char, int> last;
        for (int i = 0; i < S.size(); i++) {
            last[S[i]] = i;
        }
        
        vector<int> ans;
        // 从左往右扫，遇到字母就将当前区间的右端点扩展到该字母的最右位置
        int left = 0, right = -1;
        for (int i = 0; i < S.size(); i++) {
            right = max(right, last[S[i]]);
            if (i == right) { // 到达区间尾
                ans.push_back(i - left + 1);
                left = i + 1;
            }
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
