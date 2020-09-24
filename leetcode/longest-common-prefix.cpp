//
//  longest-common-prefix
//  https://leetcode.com/problems/longest-common-prefix/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";
        int longest = strs[0].size();
        for (int i = 1; i < strs.size(); i++) {
            longest = min(longest, (int)strs[i].size());
            for (int j = 0; j < longest; j++) {
                if (strs[0][j] != strs[i][j]) {
                    longest = j;
                    break;
                }
            }
        }
        return strs[0].substr(0, longest);
    }
};

int main(int argc, const char * argv[]) {
    vector<string> strs = {"abc", "abd", "abe"};
    Solution solution;
    cout << solution.longestCommonPrefix(strs);
    
    return 0;
}
