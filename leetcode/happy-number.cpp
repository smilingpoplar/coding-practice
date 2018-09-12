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

/*
class Solution {
public:
    bool isHappy(int n) {
        // 快慢指针法
        int fast = n, slow = n;
        while (true) {
            fast = calc(calc(fast));
            slow = calc(slow);
            if (fast == 1) return true;
            if (fast == slow) return false;
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
*/

class Solution {
public:
    bool isHappy(int n) {
        // n为m位数，每位数最大为9，每次计算结果<=81m。而m=lgn+1和n比较，由函数曲线，当n较大时81m<n。
        // 故每次计算结果<n，有限区间。如果n不是happy数，一直计算结果将重复。
        unordered_set<int> st; // 记录每次计算的结果
        while (true) {
            n = calc(n);
            if (n == 1) return true;
            if (st.count(n)) return false;
            st.insert(n);
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
