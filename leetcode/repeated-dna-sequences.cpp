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
        // 用个count记录编码出现的次数就能判重
        unordered_map<char, int> coding = {
            {'A', 0b00},
            {'C', 0b01},
            {'G', 0b10},
            {'T', 0b11},
        };
        
        const int LENGTH = 10;
        vector<string> ans;
        unordered_map<int, int> count;
        int code = 0;
        for (int i = 0; i < s.size(); i++) {
            code = ((code << 2) + coding[s[i]]) & 0xfffff;
            if (i < LENGTH - 1) continue;
            count[code]++;
            if (count[code] == 2) {
                ans.push_back(s.substr(i - LENGTH + 1, LENGTH));
            }
        }        
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.findRepeatedDnaSequences("AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT");
    for (const auto &sequence : result) {
        cout << sequence << endl;
    }
    
    return 0;
}
