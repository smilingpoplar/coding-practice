//
//  additive-number
//  https://leetcode.com/problems/additive-number/
//
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
            if (i > 1 && num[0] == '0') break;
            for (int j = 1; j <= (N - i) / 2; j++) {
                if (j > 1 && num[i] == '0') break;
                if (isValid(num, i + j, num.substr(0, i), num.substr(i, j))) return true;
            }
        }
        return false;
    }

    // num[idx..]开头是不是等于n1+n2
    bool isValid(const string &num, int idx, const string &n1, const string &n2) {
        const int N = num.size();
        if (idx == N) return true;
        auto sum = add(n1, n2);
        int len = sum.size();
        if (idx + len > N || num.substr(idx, len) != sum) return false;
        return isValid(num, idx + len, n2, sum);
    }
    
    // 数字串加法可解决超大数溢出问题
    string add(const string &a, const string &b) {
        // return to_string(stoll(a) + stoll(b));
        string ans;
        int carry = 0;
        int i = (int)a.size() - 1, j = (int)b.size() - 1;
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
