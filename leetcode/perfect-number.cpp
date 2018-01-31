//
//  perfect-number
//  https://leetcode.com/problems/perfect-number/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false;
        int sum = 1;
        for (int i = 2; i * i <= num; i++) {
            if (num % i == 0) {
                sum += i; 
                int another = num / i;
                if (another != i) sum += another;
            }
        }
        return num == sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
