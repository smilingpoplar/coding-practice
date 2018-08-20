//
//  implement-strstr
//  https://leetcode.com/problems/implement-strstr/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        const int N = haystack.size(), M = needle.size();
        for (int i = 0; i + M <= N; i++) {
            int j = 0;
            while (j < M && haystack[i+j] == needle[j]) j++;
            if (j == M) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.strStr("good luck", "luck");
    
    return 0;
}