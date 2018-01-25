//
//  self-dividing-numbers/
//  https://leetcode.com/problems/self-dividing-numbers//
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for (int i = left; i <= right; i++) {
            if (isSelfDividingNumber(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
    
    bool isSelfDividingNumber(int num) {
        int n = num;
        while (n) {
            int d = n % 10;
            if (d == 0 || num % d != 0) return false;
            n /= 10;                
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
