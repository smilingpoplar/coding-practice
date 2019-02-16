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
        // 1. 某单词要与target等长，缩略词才可能冲突，所以只考虑dictionary中与target等长的子集。
        // 2. 将某单词word与target"异或"：相同字母处取0、不同字母处取1，这样得到一个二进制数diff，
        //    只要这个diff中存在一位1（相异点），将该位取字母、其他位取数字，得到的缩写就不会冲突。
        //    注意，word[i]^target[i]对应二进制diff[N-1-i]
        // 3. 将缩写的字母处取1、数字x处取x个0，得到缩写的二进制表示abbr。
        //    当abbr&diff!=0时，abbr中存在相异点，缩写不冲突；
        //    当abbr&diff==0时，abbr中不存在相异点，缩写冲突。
        // 4. 用回溯法尝试abbr的取值：
        //    从单词的当前idx开始，或者省略连续几个字母（abbr对应位取0），或者保留字母（abbr对应位取1）。
        //    若abbr与所有diff都不冲突，这个abbr可行。
        const int N = target.size();
        set<int> diffs; // 将单词子集转为diffs集合
        for (auto &word : dictionary) {
            if (word.size() == N) {
                diffs.insert(getDiff(word, target));
            }
        }
        
        int minAbbrLen = N + 1, ansAbbr = -1; // 无效值
        search(0, N, 0, 0, diffs, minAbbrLen, ansAbbr);
        if (minAbbrLen > N) return "";
        return getAbbrStr(ansAbbr, target);
    }
    
    int getDiff(const string &word, const string &target) {
        // word[i]^target[i]对应二进制diff[N-1-i]
        int diff = 0;
        for (int i = 0; i < word.size(); i++) {
            diff <<= 1;
            diff |= word[i] != target[i];
        }
        return diff;
    }
    
    // abbr是缩写的二进制表示，abbrLen是abbr对应的串长（多位数长为1）
    void search(int idx, const int N, int abbr, int abbrLen,
                const set<int> &diffs, int &minAbbrLen, int &ansAbbr) {
        if (abbrLen >= minAbbrLen) return; // 剪枝
        
        if (idx == N) {
            for (int diff : diffs) {
                if ((abbr & diff) == 0) return; // abbr冲突
            }
            // 至此，abbr可行
            if (abbrLen < minAbbrLen) {
                minAbbrLen = abbrLen;
                ansAbbr = abbr;
            }
            return;
        }
        
        // 刚开头或上次保留了字母，这次忽略[idx..i]间的字母
        if (idx == 0 || (abbr & 1)) {
            for (int i = N - 1; i >= idx; i--) {
                search(i + 1, N, abbr << (i - idx + 1), abbrLen + 1, 
                    diffs, minAbbrLen, ansAbbr);
            }
        }
        // 或者，这次再保留字母
        search(idx + 1, N, (abbr << 1) | 1, abbrLen + 1, 
            diffs, minAbbrLen, ansAbbr);
    }
    
    string getAbbrStr(int abbr, const string &target) {
        // abbr[i]对应target[N-1-i]
        const int N = target.size();
        int cnt0s = 0;
        string ans;
        for (int i = N - 1; i >= 0; i--) {
            if (abbr & (1 << i)) {
                if (cnt0s > 0) {
                    ans += to_string(cnt0s);
                    cnt0s = 0;
                }
                ans += target[N-1-i];
            } else {
                cnt0s++;
            }
        }
        if (cnt0s > 0) ans += to_string(cnt0s);
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
