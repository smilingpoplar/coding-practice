//
//  assign-cookies
//  https://leetcode.com/problems/assign-cookies/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int i = 0, j = 0;
        while (i < g.size() && j < s.size()) {
            if (g[i] <= s[j]) i++; 
            j++;
        }
        return i;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
