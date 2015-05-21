//
//  repeated-dna-sequences
//  https://leetcode.com/problems/repeated-dna-sequences/
//
//  Created by smilingpoplar on 15/5/21.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        // 因为只有ACGT四种字符，给字符编码只要2位，给10字符长的字符串编码只要20位（掩码：0xfffff）
        // 用个counter记录编码出现的次数就能判重
        unordered_map<char, int> coding = {
            {'A', 0b00},
            {'C', 0b01},
            {'G', 0b10},
            {'T', 0b11},
        };
        
        const int kLength = 10;
        vector<string> result;
        unordered_map<int, int> counter;
        int code = 0;
        for (int i = 0; i < s.size(); ++i) {
            code = ((code << 2) + coding[s[i]]) & 0xfffff;
            if (i < kLength - 1) continue;
            ++counter[code];
            if (counter[code] == 2) {
                result.push_back(s.substr(i + 1 - kLength, kLength));
            }
        }
        
        return result;
    }
};

/* 字符串比较法超时
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        const int N = (int)s.size();
        const int kLength = 10;
        if (N < 2 * kLength) return {};
        
        vector<string> result;
        for (int i = 0; i < N - 2 * kLength; ++i) {
            for (int j = i + kLength; j < N - kLength; ++j) {
                int k = 0;
                for (; k < kLength; ++k) {
                    if (s[i + k] != s[j + k]) break;
                }
                if (k == kLength) {
                    result.push_back(s.substr(i, kLength));
                }
            }
        }
        return result;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (const auto &sequence : result) {
        cout << sequence << endl;
    }
    
    return 0;
}
