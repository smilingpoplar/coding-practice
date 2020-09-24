//
//  reverse-only-letters
//  https://leetcode.com/problems/reverse-only-letters/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string reverseOnlyLetters(string S) {
        int i = 0, j = (int)S.size() - 1;
        while (i < j) {
            while (i < j && !isalpha(S[i])) i++;
            while (i < j && !isalpha(S[j])) j--;
            if (i < j) swap(S[i++], S[j--]);
        }
        return S;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
