//
//  adding-two-negabinary-numbers
//  https://leetcode.com/problems/adding-two-negabinary-numbers/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> addNegabinary(vector<int>& arr1, vector<int>& arr2) {
        const int M = arr1.size(), N = arr2.size();
        vector<int> ans;
        int carry = 0;
        for (int i = M -1, j = N - 1; i >= 0 || j >= 0 || carry; i--, j--) {
            if (i >= 0) carry += arr1[i];
            if (j >= 0) carry += arr2[j];
            ans.push_back(carry & 1);
            carry = -(carry >> 1);
        }
        while (ans.size() > 1 && ans.back() == 0)
            ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
