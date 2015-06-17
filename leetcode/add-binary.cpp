//
//  add-binary
//  https://leetcode.com/problems/add-binary/
//
//  Created by smilingpoplar on 15/6/17.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string result;
        int i = (int)a.size() - 1;
        int j = (int)b.size() - 1;
        int carry = 0;
        while (i >= 0 || j >= 0 || carry > 0) {
            int sum = (i >= 0 ? a[i] - '0' : 0) + (j >= 0 ? b[j] - '0' : 0) + carry;
            result.push_back((sum & 1) + '0');
            carry = (sum >> 1);
            --i;
            --j;
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.addBinary("11", "1");
 
    return 0;
}