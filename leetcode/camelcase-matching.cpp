//
//  camelcase-matching
//  https://leetcode.com/problems/camelcase-matching/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> ans;
        for (auto& query : queries) {
            ans.push_back(camelMatch(query, pattern));
        }
        return ans;
    }
    
    bool camelMatch(const string& query, string pattern) {
        const int M = query.size(), N = pattern.size();
        int j = 0;
        for (int i = 0; i < M; i++) {
            if (j < N && query[i] == pattern[j]) {
                j++;
            } else if (isupper(query[i])) {
                return false; // query中的大写字母必须马上匹配
            }
        }
        return j == N;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
