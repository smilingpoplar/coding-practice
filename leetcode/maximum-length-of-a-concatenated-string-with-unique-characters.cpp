//
//  maximum-length-of-a-concatenated-string-with-unique-characters
//  https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        // 回溯法
        int ans = 0;
        search(arr, 0, "", ans);
        return ans;
    }
    
    void search(vector<string> &arr, int idx, const string &conc, int &ans) {
        const int N = arr.size();
        if (idx == N) return;
        
        for (int i = idx; i < N; i++) {
            if (!isUnique(arr[i], conc)) continue;
            auto nconc = conc + arr[i];
            ans = max(ans, (int)nconc.size());
            search(arr, i + 1, nconc, ans);
        }
    }
    
    bool isUnique(const string &s, const string &conc) {
        vector<int> count(26, 0);
        for (auto c : conc) {
            count[c - 'a'] = 1; 
        }
        for (auto c : s) {
            if (count[c - 'a']) return false;
            count[c - 'a'] = 1;
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
