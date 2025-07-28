//
//  addition-36
//  NC330 36进制加法
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string thirtysixAdd(string A, string B) {
        const int M = A.size(), N = B.size();
        int i = M - 1, j = N - 1;
        int carry = 0;
        string ans;
        while (i >= 0 || j >= 0 || carry > 0) {
            if (i >= 0) carry += toNum(A[i--]);
            if (j >= 0) carry += toNum(B[j--]);
            ans.push_back(toChar(carry % 36));
            carry /= 36;
        }

        reverse(begin(ans), end(ans));
        return ans;
    }

    int toNum(char c) {
        if ('0' <= c && c <= '9') return c - '0';
        return c - 'a' + 10;
    }

    char toChar(int num) {
        if (0 <= num && num <= 9) return '0' + num;
        return num - 10 + 'a';
    }
};