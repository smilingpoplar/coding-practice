//
//  restore-ip-addresses
//  https://leetcode.com/problems/restore-ip-addresses/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
    const int TOTAL_PART_COUNT = 4;
    const int MIN_PART_SIZE = 1;
    const int MAX_PART_SIZE = 3;
public:
    vector<string> restoreIpAddresses(string s) {
        vector<string> ans;
        vector<string> parts;
        search(s, 0, parts, ans);
        return ans;
    }
    
    void search(const string &s, int idx,
             vector<string> &parts, vector<string> &ans) {
        const int N = s.size();
        if (parts.size() == TOTAL_PART_COUNT) {
            if (idx == N) {
                ostringstream oss;
                for (int i = 0; i < TOTAL_PART_COUNT; i++) {
                    oss << parts[i];
                    if (i < TOTAL_PART_COUNT - 1) oss << ".";
                }
                ans.push_back(oss.str());
            }
            return;
        }
        
        // partSize = (N - idx) / (TOTAL_PART_COUNT - parts.size())
        if (N - idx < (TOTAL_PART_COUNT - parts.size()) * MIN_PART_SIZE) return;
        if (N - idx > (TOTAL_PART_COUNT - parts.size()) * MAX_PART_SIZE) return;
        
        for (int sz = MIN_PART_SIZE; sz <= MAX_PART_SIZE && idx + sz <= N; sz++) {
            // 验证子段是否合法
            if (sz > 1 && s[idx] == '0') continue;
            string part = s.substr(idx, sz);
            if (stoi(part) > 255) continue;

            parts.push_back(part);
            search(s, idx + sz, parts, ans);
            parts.pop_back();
        }
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto ans = solution.restoreIpAddresses("010010");
    for (auto ip : ans) {
        cout << ip << endl;
    }
    
    return 0;
}
