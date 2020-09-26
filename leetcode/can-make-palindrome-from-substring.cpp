//
//  can-make-palindrome-from-substring
//  https://leetcode.com/problems/can-make-palindrome-from-substring/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
        // "前缀和"preOdds[i+1]对应s[0..i]，各个位对应各字符的奇偶性
        vector<int> preOdds = {0};
        int runningOdds = 0;
        for (char c : s) {
            runningOdds ^= 1 << (c - 'a');
            preOdds.push_back(runningOdds);
        }
        
        vector<bool> ans;
        for (auto &query : queries) {
            // 回文需要oddCnt/2<=k
            int odds = preOdds[query[1] + 1] ^ preOdds[query[0]];
            int oddCnt = bitset<26>(odds).count();
            ans.push_back(oddCnt / 2 <= query[2]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
