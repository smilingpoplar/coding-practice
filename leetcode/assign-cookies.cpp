//
//  assign-cookies
//  https://leetcode.com/problems/assign-cookies/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0;
        for (int j = 0; j < s.size() && i < g.size(); j++) {
            if (g[i] <= s[j]) i++; 
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
