//
//  restore-ip-addresses
//  https://leetcode.com/problems/restore-ip-addresses/
//
//  Created by smilingpoplar on 15/6/6.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> result;
        vector<string> parts;
        dfs(0, 0, s, parts, result);
        return result;
    }
private:
    const int TOTAL_PART_COUNT = 4;
    const int PART_MIN_SIZE = 1;
    const int PART_MAX_SIZE = 3;
    
    void dfs(int partCount, int startIndex, const string &s,
             vector<string> &parts, vector<string> &result) {
        const int N = (int)s.size();
        if (partCount == TOTAL_PART_COUNT) {
            if (startIndex == N) {
                ostringstream oss;
                for (int i = 0; i < TOTAL_PART_COUNT; ++i) {
                    oss << parts[i];
                    if (i < TOTAL_PART_COUNT - 1) oss << ".";
                }
                result.push_back(oss.str());
            }
            return;
        }
        
        if (N - startIndex < (TOTAL_PART_COUNT - partCount) * PART_MIN_SIZE) return;
        if (N - startIndex > (TOTAL_PART_COUNT - partCount) * PART_MAX_SIZE) return;
        
        for (int partSize = PART_MIN_SIZE; partSize <= PART_MAX_SIZE && startIndex + partSize <= s.size(); ++partSize) {
            // 验证子段是否合法
            if (partSize > 1 && s[startIndex] == '0') continue;
            string part = s.substr(startIndex, partSize);
            if (stoi(part) > 255) continue;

            parts.push_back(part);
            dfs(partCount + 1, startIndex + partSize, s, parts, result);
            parts.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.restoreIpAddresses("010010");
    for (const auto ip : result) {
        cout << ip << endl;
    }
    
    return 0;
}
