//
//  nth-digit
//  https://leetcode.com/problems/nth-digit/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findNthDigit(int n) {
        // [1..9]：1*9，[10..99]：2*90，[100..999]：3*900，...
        // 每部分的个数：len*count
        int len = 1, count = 9, start = 1;
        while (count < n / len) { // len * count < n
            n -= len * count;
            len++;
            count *= 10;
            start *= 10;
        }
        
        n--; // n变成0-based索引
        start += n / len;
        string s = to_string(start);
        return s[n % len] - '0';
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
