//
//  find-and-replace-in-string
//  https://leetcode.com/problems/find-and-replace-in-string/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string findReplaceString(string S, vector<int>& indexes, vector<string>& sources, vector<string>& targets) {
        // 先找出所有要替换的区间
        const int N = indexes.size();
        vector<int> replaces;
        for (int i = 0; i < N; i++) {
            if (startsWith(S, indexes[i], sources[i])) replaces.push_back(i);
        }
        sort(replaces.begin(), replaces.end(), [&indexes](int a, int b) {
            return indexes[a] < indexes[b];
        });
        
        // 类似区间合并，每个replace区间是[indexes[i]..indexes[i]+sources[i].size())
        string ans;
        int start = 0;
        for (int i : replaces) {
            int iStart = indexes[i], iEnd = iStart + sources[i].size();
            if (iStart > start) ans += S.substr(start, iStart - start);
            ans += targets[i]; // S[iStart..iEnd)替换成targets[i]
            start = iEnd;
        }
        if (start < S.size()) ans += S.substr(start, S.size() - start);
        return ans;
    }
    
    bool startsWith(const string &s, int si, const string &src) {
        return s.find(src, si) == si;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
