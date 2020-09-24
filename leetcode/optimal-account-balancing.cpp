//
//  optimal-account-balancing
//  https://leetcode.com/problems/optimal-account-balancing/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int, int> mp;
        for (auto &t : transactions) {
            mp[t[0]] -= t[2];
            mp[t[1]] += t[2];
        }
        vector<int> debts;
        for (auto &e : mp) {
            int debt = e.second;
            if (debt) debts.push_back(debt);
        }
        return dfs(0, debts);
    }
    
    int dfs(int start, vector<int> &debts) {
        // 找第一个非0值
        while (start < debts.size() && debts[start] == 0) start++;
        // 合并到后面的异号项中
        int cnt = INT_MAX;
        for (int i = start + 1; i < debts.size(); i++) {
            if ((debts[i] ^ debts[start]) < 0) {
                debts[i] += debts[start];
                cnt = min(cnt, 1 + dfs(start + 1, debts));
                debts[i] -= debts[start];
            }
        }
        return cnt != INT_MAX ? cnt : 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
