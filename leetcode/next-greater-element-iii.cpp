//
//  next-greater-element-iii
//  https://leetcode.com/problems/next-greater-element-iii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int nextGreaterElement(int n) {
        // 1. 从右往左，找s[i]<s[i+1]的第一个i
        // 2. 在i后面找比s[i]大的最小数s[idx]
        // 3. 交换s[i]和s[idx]
        // 4. 排序s[i+1..]
        string s = to_string(n);
        for (int i = s.size() - 2; i >= 0; i--) {
            // 1
            if (s[i] < s[i + 1]) {
                // 2
                int smallest = INT_MAX, idx;
                for (int j = i + 1; j < s.size(); j++) {
                    if (s[j] > s[i] && s[j] < smallest) {
                        smallest = s[j];
                        idx = j;
                    }
                }
                // 3
                char tmp = s[i];
                s[i] = s[idx];
                s[idx] = tmp;
                // 4
                sort(s.begin() + i + 1, s.end());
                long ans = stol(s); // 溢出判断
                return (ans <= INT_MAX) ? ans : -1;
            }
        }
        return -1;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
