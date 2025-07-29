//
//  substract-strings
//  NC359 大数相减
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string substring(string num1, string num2) {
        const int M = num1.size(), N = num2.size();
        if ((M < N) || (M == N && num1 < num2)) {
            return "-" + substring(num2, num1);
        }

        string ans;
        int i = M - 1, j = N - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry < 0) {
            int diff = carry;
            if (i >= 0) diff += num1[i] - '0';
            if (j >= 0) diff -= num2[j] - '0';

            if (diff < 0) {
                diff += 10;
                carry = -1;
            } else {
                carry = 0;
            }
            ans.push_back(diff + '0');
            i--;
            j--;
        }

        while (ans.size() > 1 && ans.back() == '0') {
            ans.pop_back();
        }
        reverse(begin(ans), end(ans));
        return ans;
    }
};
