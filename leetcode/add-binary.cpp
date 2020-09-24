//
//  add-binary
//  https://leetcode.com/problems/add-binary/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i = (int)a.size() - 1, j = (int)b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            carry += (i >= 0 ? a[i] - '0' : 0);
            carry += (j >= 0 ? b[j] - '0' : 0);
            ans.push_back((carry & 1) + '0');
            carry >>= 1;
            i--, j--;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.addBinary("11", "1");
 
    return 0;
}
