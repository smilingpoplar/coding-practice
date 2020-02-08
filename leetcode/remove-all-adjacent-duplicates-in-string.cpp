//
//  remove-all-adjacent-duplicates-in-string
//  https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        string ans;
        for (char c : S) {
            if (!ans.empty() && ans.back() == c) {
                ans.pop_back();
            } else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
