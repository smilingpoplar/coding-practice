//
//  unique-letter-string
//  https://leetcode.com/problems/unique-letter-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int uniqueLetterString(string S) {
        // 所有子串的UNIQ(sub)之和 <=等价于=> 所有只含某字母一次的子串数
        // 比如AB,A,B的UNIQ()之和=2+1+1=4 <=等价于=> 只含A一次的子串数+只含B一次的子串数=2+2=4
        // 只含某字母一次，比如看XAXAXXAX的第二个A，可以XA(XAXX)AX、XAX(AXX)AX、...
        // 左括号'('加在(idxA1,idxA2]，右括号')'加在[idxA2,idxA3)，子串数(idxA2-idxA1)*(idxA3-indxA2)
        const int N = S.size();
        unordered_map<char, vector<int>> mp; // char => idx list
        for (int i = 0; i < N; i++) {
            mp[S[i]].push_back(i);
        }
        
        const int MOD = 1e9 + 7;
        int ans = 0;
        for (auto &e : mp) {
            auto &idx = e.second;
            int len = idx.size();
            for (int i = 0; i < len; i++) {
                int prev = (i > 0) ? idx[i-1] : -1;
                int next = (i + 1 < len) ? idx[i+1] : N;
                ans = (ans + (idx[i] - prev) * (next - idx[i])) % MOD;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
