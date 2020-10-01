//
//  split-a-string-into-the-max-number-of-unique-substrings
//  https://leetcode.com/problems/split-a-string-into-the-max-number-of-unique-substrings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxUniqueSplit(string s) {
        const int N = s.size();
        unordered_set<string> seen;
        int ans = 0;
        // 分割s[idx..]
        function<void(int)> dfs = [&](int idx) {
            if (idx == N) {
                ans = max(ans, (int)seen.size());
                return;
            }
            for (int i = idx; i < N; i++) {
                // 分出s[idx..i]
                auto [sub, succ] = seen.insert(s.substr(idx, i - idx + 1));
                if (!succ) continue; // 已见过
                dfs(i + 1);
                seen.erase(sub);                
            }
        };
        
        dfs(0);
        return ans;
    }  
};

int main(int argc, const char * argv[]) {    
    return 0;
}
