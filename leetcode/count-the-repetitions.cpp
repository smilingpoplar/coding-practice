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
    // https://leetcode.com/problems/count-the-repetitions/solution/
    int getMaxRepetitions(string s1, int n1, string s2, int n2) {
        // 在S1=[s1,n1]中连续找s2。
        // 每个s1扫描之前记录：s2指针i2指到哪儿了、s2完整出现了几次
        // i2起先指向0，由鸽笼原理，i2在扫描完s2.size()个s1后肯定出现重复，故只需记录s2.size()+1个变量
        vector<int> idx(s2.size() + 1);
        vector<int> cnt(s2.size() + 1);
        int i2 = 0, s2cnt = 0;
        idx[0] = i2, cnt[0] = s2cnt; // 第0个s1扫描之前

        for (int i = 1; i <= n1; i++) {
            // 扫描s1
            for (int i1 = 0; i1 < s1.size(); i1++) {
                if (s1[i1] == s2[i2]) i2++;
                if (i2 == s2.size()) {
                    i2 = 0;
                    s2cnt++;
                }
            }
            idx[i] = i2;
            cnt[i] = s2cnt;
            
            // 看i2是否曾经出现过
            for (int k = 0; k < i; k++) {
                if (idx[k] == i2) {
                    // 以前第k个、现在第i个s1扫描之前都出现i2，[k,i)的s1构成重复模式；
                    // 看模式前、模式中、模式后三段分别消耗几个s2
                    int prefixCnt = cnt[k] - cnt[0];
                    int onePatternCnt = cnt[i] - cnt[k], totalPattern = (n1 - k) / (i - k);
                    int patternsCnt = onePatternCnt * totalPattern;
                    int remain = (n1 - k) % (i - k), end = k + remain;
                    int suffixCnt = cnt[end] - cnt[k];
                    return (prefixCnt + patternsCnt + suffixCnt) / n2;
                }
            }
        }
        return (cnt[n1] - cnt[0]) / n2;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
