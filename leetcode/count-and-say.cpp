//
//  count-and-say
//  https://leetcode.com/problems/count-and-say/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s("1");
        while (--n) {
            ostringstream oss;
            int i = 0;
            int j = 0;
            while (i < s.size()) {
                while (j < s.size() && s[j] == s[i]) ++j;
                oss << j - i << s[i]; // count&say
                i = j;
            }
            s = oss.str();
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.countAndSay(5);
    
    return 0;
}
