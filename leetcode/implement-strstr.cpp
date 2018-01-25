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
        const int M = (int)haystack.size();
        const int N = (int)needle.size();
        for (int i = 0; i + N <= M; i++) {
            int j = 0;
            while (j < N && haystack[i + j] == needle[j]) ++j;
            if (j == N) return i;
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.strStr("good luck", "luck");
    
    return 0;
}