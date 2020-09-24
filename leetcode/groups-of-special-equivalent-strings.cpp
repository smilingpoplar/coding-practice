//
//  groups-of-special-equivalent-strings
//  https://leetcode.com/problems/groups-of-special-equivalent-strings/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        // 给每个串算个签名，已知串中偶数位可跟偶数位交换、奇数位可跟奇数位交换
        unordered_set<string> st;
        for (auto &s : A) {
            string cnt(52, 0); // 1<=len(s)<=20，用一个字节可计数
            for (int i = 0; i < s.size(); i++) {
                cnt[s[i] - 'a' + (i & 1) * 26]++;
            }
            st.insert(cnt);
        }
        return st.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
