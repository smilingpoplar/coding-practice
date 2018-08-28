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
        // 从左往右看各位置，看有没有尽量比当前数字大的数字在后面，交换
        string s = to_string(num);
        vector<int> pos(10, -1);
        for (int i = 0; i < s.size(); i++) {
            pos[s[i] - '0'] = i;
        }
        
        for (int i = 0; i < s.size(); i++) {
            for (int x = 9; x > s[i] - '0'; x--) {
                if (pos[x] > i) {
                    swap(s[pos[x]], s[i]);
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
