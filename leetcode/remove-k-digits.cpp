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
        // 使数字串最小，需要留下递增序列 <=> 找下一个更小的数；在此基础上，考虑限制条件：
        // 当栈内数字个数+剩余可压栈个数>needed时才可pop()，栈内数字个数<needed时才可push()
        const int N = num.size(), needed = N - k;
        string s;
        for (int i = 0; i < N; i++) {
            while (!s.empty() && num[i] < s.back() 
                   && s.size() + (N - i) > needed) { // [i,N)是剩余可压栈的数字
                s.pop_back();
            }
            if (s.size() < needed) s.push_back(num[i]);
        }
        // 删除开头的0
        int pos = 0;
        while (pos < s.size() && s[pos] == '0') pos++;      
        return pos < s.size() ? s.substr(pos) : "0";
    }
};

/*
class Solution {
public:
     string removeKdigits(string num, int k) {
         // 想象数字构成的高低折线，削掉第一个波峰就能使数字尽量小，从左往右削掉k个波峰
         // 用栈找波峰 <=> 找下一个更小的数
         string s;
         for (char c : num) {
             while (!s.empty() && c < s.back() && k > 0) {
                 s.pop_back();
                 k--;
             }
             s.push_back(c);
         }
         // 若上面削掉的不足k个，再去掉末尾最大的几个数字
         while (!s.empty() && k > 0) {
             s.pop_back();
             k--;
         }
         // 删除开头的0
         int pos = 0;
         while (pos < s.size() && s[pos] == '0') pos++;
         return pos < s.size() ? s.substr(pos) : "0";
     }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
