//
//  happy-number
//  https://leetcode.com/problems/happy-number/
//
//  Created by smilingpoplar on 15/5/4.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <unordered_set>

using namespace std;

class Solution {
public:
    bool isHappy(int n) {
        // 设n为m位数，每位数最大为9，因此每次计算的结果 <= 81m，而 81m < 10^(m-1) <= n (当m较大时，如m>=4)，
        // 也就是说，每次计算的结果落在有限区间内，如果n不是happy数，不断计算下去计算结果将出现重复
        unordered_set<int> results; // 记录每次计算的结果
        int result = n;
        while (true) {
            result = calc(result);
            if (result == 1) return true;
            if (results.count(result)) return false;
            results.insert(result);
        }
    }

    int calc(int n) {
        int sum = 0;
        while (n) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.isHappy(19);
    cout << solution.isHappy(89);
    
    return 0;
}
