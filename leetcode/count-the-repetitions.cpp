//
//  count-the-repetitions
//  https://leetcode.com/problems/count-the-repetitions/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    // https://leetcode.com/problems/count-the-repetitions/discuss/95398/C++-solution-inspired-by-@70664914-with-organized-explanation
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // repeatCount[k]记录：s1的第k次出现匹配完后，s2匹配过几次。
        // 若匹配次数为s2.size()，由起始匹配位置的鸽笼原理，肯定开始重复。
        vector<int> s2Count(s2.size() + 1);
        // nextIdx[k]记录：s1的第k次出现匹配完后，下一个要匹配s2中的哪个元素。
        vector<int> nextIdx(s2.size() + 1);
        int j = 0, count = 0;
        for (int k = 1; k <= n1; k++) {
            for (int i = 0; i < s1.size(); i++) {
                if (s1[i] == s2[j]) j++;
                if (j == s2.size()) {
                    j = 0;
                    count++;
                }
            }
            s2Count[k] = count;
            nextIdx[k] = j;
            
            // 看下一个要匹配的s2中元素是否已出现过
            for (int start = 0; start < k; start++) {
                if (nextIdx[start] == nextIdx[k]) { // 若出现过，统计pattern开始前、pattern中、pattern结束后三段
                    int s2CountForPrefix = s2Count[start];
                    int s2CountForOnePattern = s2Count[k] - s2Count[start], patternCount = (n1 - start) / (k - start);
                    int s2CountForPatterns = s2CountForOnePattern * patternCount;
                    int end = start + (n1 - start) % (k - start);
                    int s2CountForSuffix = s2Count[end] - s2Count[start];
                    return (s2CountForPrefix + s2CountForPatterns + s2CountForSuffix) / n2;
                }
            }
        }
        return s2Count[n1] / n2;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
