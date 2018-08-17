//
//  split-array-into-fibonacci-sequence
//  https://leetcode.com/problems/split-array-into-fibonacci-sequence/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> splitIntoFibonacci(string S) {
        vector<int> ans;
        search(S, 0, ans);
        return ans;
    }
    
    bool search(const string &s, int idx, vector<int> &ans) {
        const int N = s.size(), M = ans.size();
        if (idx == N && M >= 3) return true;
        
        // s[idx..i]分割出数num
        for (int i = idx; i < N; i++) {
            if (i > idx && s[idx] == '0') continue; // 多位数的首位不能为0
            int len = i - idx + 1;
            if (len > 10) continue; // < 2^31, 最多10位数
            long num = stol(s.substr(idx, len));
            if (num > INT_MAX) continue; // 太大溢出
            if (M >= 2 && ans[M-2] + ans[M-1] != num) continue; // 不满足Fibonacci性质
            ans.push_back(num);
            if (search(s, i + 1, ans)) return true;
            ans.pop_back();
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
