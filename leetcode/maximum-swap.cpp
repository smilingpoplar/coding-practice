//
//  maximum-swap
//  https://leetcode.com/problems/maximum-swap/
//
//  Created by smilingpoplar on 18/01/18.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maximumSwap(int num) {
        // 从左往右看各位置，看有没有比当前数字尽量大的数字在最后面，有就交换
        string s = to_string(num);
        const int N = s.size();
        vector<int> lastIdx(10, -1);
        for (int i = 0; i < N; i++) {
            lastIdx[s[i] - '0'] = i;
        }
        
        for (int i = 0; i < N; i++) {
            for (int x = 9; x > s[i] - '0'; x--) {
                if (lastIdx[x] > i) {
                    swap(s[i], s[lastIdx[x]]);
                    return stoi(s);
                }
            }
        }
        return num;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
