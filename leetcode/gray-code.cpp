//
//  gray-code
//  https://leetcode.com/problems/gray-code/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        for (int i = 0; i < 1 << n; i++) {
            ans.push_back(i ^ (i >> 1));
        }
        return ans;    
    }
};

/*
class Solution {
public:
    vector<int> grayCode(int n) {
        // n位格雷码的序列可分作上下两半：
        //  上半是n-1位格雷码序列、前面拼上0；下半是n-1位格雷码的逆序列、前面拼上1
        // 反过来，已知n位格雷码序列，把它当作n+1位格雷码序列的上半部，
        //  逆序遍历并在前面拼上1，就得n+1位格雷码序列的下半部
        vector<int> ans;
        ans.push_back(0); // n==0
        for (int i = 0; i < n; i++) { // 拼n次
            for (int j = (int)ans.size() - 1; j >= 0; j--) {
                ans.push_back(ans[j] | (1 << i));
            }
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    Solution solution;
    auto ans = solution.grayCode(2);
    for (int code : ans) {
        cout << code << " ";
    }
    
    return 0;
}
