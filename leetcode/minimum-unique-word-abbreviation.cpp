//
//  minimum-unique-word-abbreviation
//  https://leetcode.com/problems/minimum-unique-word-abbreviation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string minAbbreviation(string target, vector<string>& dictionary) {
        // 1. 某单词要与target等长，它们的缩略词才可能冲突，所以只考虑dictionary中与target等长的子集。
        // 2. 将某单词word与target"异或"：相同字符处取0、不同字符处取1，这样得到一个二进制数diff，
        //    只要这个二进制数中存在一位1，那么该比特1处取字母、其他位省略成数字，就能得到不冲突的缩写。
        // 3. 另一方面，如果将缩写的字母处取1、x数字处取x个0，这样得到一个二进制数abbr，
        //    当abbr&diff!=0时，diff中至少一位1在abbr中以字母存在，abbr是不冲突的缩写。
        // 4. 用回溯法尝试abbr的取值：从当前pos开始，或者省略连续几个字母（abbr对应位取0），或者保留字母（abbr对应位取1）
        const int N = target.size();
        set<int> diffs;
        for (auto &word : dictionary) {
            if (word.size() == N) {
                diffs.insert(getDiff(word, target));
            }
        }
        
        int minAbbrStrLen = N + 1; // 无效值
        int ansAbbr = -1;
        dfs(0, N, 0, 0, diffs, minAbbrStrLen, ansAbbr);
        if (minAbbrStrLen > N) return "";
        return getAbbrStr(ansAbbr, target);
    }
    
    int getDiff(const string &word, const string &target) {
        // 第i位字母的比较结果对应diff[N-1-i]位
        int diff = 0;
        for (int i = 0; i < word.size(); i++) {
            diff <<= 1;
            diff |= word[i] != target[i];
        }
        return diff;
    }
    
    void dfs(int idx, const int N, int abbr, int abbrStrLen, // abbrStrLen指abbr对应的字符串长
             const set<int> &diffs, int &minAbbrStrLen, int &ansAbbr) {
        if (abbrStrLen >= minAbbrStrLen) return; // 剪枝
        
        if (idx == N) {
            for (int diff : diffs) {
                if ((abbr & diff) == 0) return; 
            }
            // 到此，abbr合法
            if (abbrStrLen < minAbbrStrLen) {
                minAbbrStrLen = abbrStrLen;
                ansAbbr = abbr;
            }
            return;
        }
        
        // 上次保留了字母，这次忽略[idx..i]间的字母
        if (idx == 0 || (abbr & 1)) {
            for (int i = N - 1; i >= idx; i--) {
                dfs(i + 1, N, abbr << (i - idx + 1), abbrStrLen + 1, diffs, minAbbrStrLen, ansAbbr);
            }
        }
        // 或者，这次保留字母
        dfs(idx + 1, N, (abbr << 1) | 1, abbrStrLen + 1, diffs, minAbbrStrLen, ansAbbr);
    }
    
    string getAbbrStr(int abbr, const string &target) {
        const int N = target.size();
        string ans;
        int count0s = 0;
        // abbr[i]位对应target[N-1-i]
        for (int i = N - 1; i >= 0; i--) {
            if (abbr & (1 << i)) {
                if (count0s > 0) {
                    ans += to_string(count0s);
                    count0s = 0;
                }
                ans += target[N-1-i];
            } else {
                count0s++;
            }
        }
        if (count0s > 0) ans += to_string(count0s);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
