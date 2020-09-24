//
//  minimum-remove-to-make-valid-parentheses
//  https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        const int N = s.size();
        vector<int> misIdx; // 不匹配的括号位置
        for (int i = 0; i < N; i++) {
            if (s[i] == '(') {
                misIdx.push_back(i);
            } else if (s[i] == ')') {
                if (!misIdx.empty() && s[misIdx.back()] == '(') {
                    misIdx.pop_back();
                } else {
                    misIdx.push_back(i);                    
                }
            }
        }
        
        for (auto it = misIdx.rbegin(); it != misIdx.rend(); it++) {
            s.erase(s.begin() + *it);
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
