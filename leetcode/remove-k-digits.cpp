//
//  remove-k-digits
//  https://leetcode.com/problems/remove-k-digits/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        const int N = num.size();
        int cnt = N - k; // 删掉k个数字就是留下N-k个数字
        // 栈中留下递增序列、对应于波峰的左侧、找下一个更小的数
        // 当栈内数字个数+剩余可压栈个数>cnt时才可pop()，栈内数字个数<cnt时才可push()
        string s;
        for (int i = 0; i < N; i++) {
            while (!s.empty() && num[i] < s.back() 
                   && s.size() + (N - i) > cnt) { // [i,N)是剩余可压栈的数字
                s.pop_back();
            }
            if (s.size() < cnt) s.push_back(num[i]);
        }
        // 删除开头的0
        int pos = 0;
        while (pos < s.size() && s[pos] == '0') pos++;        
        return pos < s.size() ? s.substr(pos) : "0";
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
