//
//  number-of-substrings-containing-all-three-characters
//  https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numberOfSubstrings(string s) {
        const int N = s.size();
        unordered_map<int, int> cnt; // char=>count
        int ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            cnt[s[hi]]++;
            while (cnt['a'] && cnt['b'] && cnt['c']) {
                cnt[s[lo++]]--;
            }
            // 现在[lo..hi]里字符不够，但前面的lo=[0..lo-1]都够
            ans += lo; // 关键是这里，在不合法状态计算合法状态数
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
