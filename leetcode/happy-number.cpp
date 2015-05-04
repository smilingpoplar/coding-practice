//
//  happy-number.cpp
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
        // 设n的位数为m，每位数字最大为9，每次计算的结果最大为81m，而 81m < 10^(m-1) <= n (当m>=4时)，
        // 因此每次计算的结果落在一个有限区间，如果n不是happy数，计算结果一直进行下去将出现循环
        unordered_set<int> results; // 用一个集合记录每次计算的结果
        int result = n;
        while (true) {
            result = calc(result);
            if (result == 1) return true;
            if (results.find(result) != results.end()) return false;
            results.insert(result);
        }
    }
private:
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
