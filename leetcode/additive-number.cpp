//
//  additive-number
//  https://leetcode.com/problems/additive-number/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isAdditiveNumber(string num) {
        // 选头两个数字长为i和j
        const int N = num.size();
        for (int i = 1; i <= N / 2; i++) {
            if (i > 1 && num[0] == '0') return false;
            for (int j = 1; j <= (N - i) / 2; j++) {
                if (j > 1 && num[i] == '0') break;
                if (isValid(num, 0, num.substr(0, i), num.substr(i, j))) return true;
            }
        }
        return false;
    }

    // num[idx..]是不是以n1和n2开头
    bool isValid(const string &num, int idx, const string &n1, const string &n2) {
        auto sum = add(n1, n2);
        auto left = num.substr(idx + n1.size() + n2.size());
        if (sum == left) return true;
        if (sum.size() > left.size() || left.substr(0, sum.size()) != sum) return false;
        return isValid(num, idx + n1.size(), n2, sum);        
    }
    
    string add(const string &a, const string &b) {
        // return to_string(stoll(a) + stoll(b));
        string ans;
        int carry = 0;
        int i = a.size() - 1, j = b.size() - 1;
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) carry += a[i--] - '0';
            if (j >= 0) carry += b[j--] - '0';
            ans.push_back(carry % 10 + '0');
            carry /= 10;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
