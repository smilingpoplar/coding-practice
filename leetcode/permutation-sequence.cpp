//
//  permutation-sequence
//  https://leetcode.com/problems/permutation-sequence/
//
//  Created by smilingpoplar on 15/5/28.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 首元素固定后剩余元素有(n-1)!种排列，
        // 第k（0-based）个排列的首元素是 k/(n-1)!
        vector<int> f(n, 1); // f[i]=i!
        for (int i = 1; i < n; i++) f[i] = i * f[i-1];
        string s;
        for (int i = 0; i < n; i++) s += '1' + i;
        
        k--; // k变成0-based
        string ans;
        while (n) {
            int idx = k / f[n-1];
            ans += s[idx];
            k %= f[n-1], n--;
            s.erase(s.begin() + idx); // 剩余元素要保持有序
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.getPermutation(3, 5);
    
    return 0;
}
