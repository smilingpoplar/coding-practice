//
//  gray-code
//  https://leetcode.com/problems/gray-code/
//
//  Created by smilingpoplar on 15/6/24.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        // 观察几个格雷码的例子，n位的格雷码可以分作上下两部分：
        // 上半部是n-1位格雷码（前面加个0），下半部是n-1位格雷码的倒序前面加个1
        vector<int> result;
        result.push_back(0); // n==0
        for (int i = 0; i < n; i++) {
            for (int j = (int)result.size() - 1; j >= 0; j--) {
                result.push_back(result[j] | (1 << i));
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    auto result = solution.grayCode(2);
    for (int code : result) {
        cout << code << " ";
    }
    
    return 0;
}
