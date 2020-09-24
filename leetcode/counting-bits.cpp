//
//  counting-bits
//  https://leetcode.com/problems/counting-bits/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> f(num + 1);
        f[0] = 0;
        for (int i = 1; i <= num; i++) {
            f[i] = f[i & (i-1)] + 1;
        }
        return f;            
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
