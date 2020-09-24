//
//  rotated-digits
//  https://leetcode.com/problems/rotated-digits/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int rotatedDigits(int N) {
        int count = 0;
        for (int i = 1; i <= N; i++) {
            if (isValid(i)) count++;
        }
        return count;
    }
    
    int isValid(int n) {
        bool found = false;
        while (n) {
            int d = n % 10;
            if (d == 3 || d == 4 || d == 7) return false;
            if (d == 2 || d == 5 || d == 6 || d == 9) found = true;
            n /= 10;
        }
        return found;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
