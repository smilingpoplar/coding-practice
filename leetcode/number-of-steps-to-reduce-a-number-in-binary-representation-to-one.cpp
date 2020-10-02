//
//  number-of-steps-to-reduce-a-number-in-binary-representation-to-one
//  https://leetcode.com/problems/number-of-steps-to-reduce-a-number-in-binary-representation-to-one/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numSteps(string s) {
        const int N = s.size();
        int ans = 0, carry = 0;
        // 要变成1，留1位，i>0
        for (int i = N - 1; i > 0; i--) {
            ans++; // 最终都得除2
            // (s[i]-'0')  carry  +
            //     0        0     0   要除2，carry=0
            //     0        1     1   要加1、除2，carry=1
            //     1        0     1   要加1、除2，carry=1
            //     1        1     0   要除2，carry=1
            if (s[i] - '0' + carry == 1) {
                ans++;     // 加1
                carry = 1; // 进位
            } // else，carry保持不变
            
        }
        ans += carry;
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
