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

/*
class Solution {
public:
     string removeKdigits(string num, int k) {
         // 想象数字构成的高低折线，削掉第一个波峰就能使数字尽量地变小，
         // 因此从左往右削掉k个波峰
         // 用栈找"波峰"、找下一个更小的数
         string s;
         for (char c : num) {
             while (!s.empty() && c < s.back() && k > 0) {
                 s.pop_back();
                 k--;
             }
             s.push_back(c);
         }
         // 上面削掉的若不够k个，再去掉末尾最大的几个
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
