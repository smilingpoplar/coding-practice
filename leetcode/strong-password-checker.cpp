//
//  strong-password-checker
//  https://leetcode.com/problems/strong-password-checker/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int strongPasswordChecker(string s) {
        const int N = s.size();
        int needLower = 1, needUpper = 1, needDigit = 1;
        int modifyOp = 0;
        vector<int> type(3, 0);
        // 长len>=3的重复子串，按照len%3分三类，用type[len%3]计数
        // 假设已进行过修改操作，比如aaaaaa已修改成aa#aa#
        // len%3==0这类子串，末尾可用1个删除省掉1个修改，比如 aa#aa#   => aa#aa
        // len%3==1这类子串，末尾可用2个删除省掉1个修改，比如 aa#aa#a  => aa#aa
        // len%3==2这类子串，末尾可用3个删除省掉1个修改，比如 aa#aa#aa => aa#aa        
        for (int i = 0, j; i < N; i = j) {
            if(islower(s[i])) needLower = 0;
            else if(isupper(s[i])) needUpper = 0;
            else if(isdigit(s[i])) needDigit = 0;
            
            j = i + 1;
            while (j < N && s[j] == s[i]) j++;
            int len = j - i;
            if (len >= 3) {
                modifyOp += len / 3; // 每3个字母修改第3个
                type[len % 3]++;
            }                
        }
        
        int needLUD = needLower + needUpper + needDigit;
        if (N < 6) return max(6 - N, needLUD); // 只需插入操作
        if (N <= 20) return max(modifyOp, needLUD); // 只需修改操作
        // N > 20
        const int needDelete = N - 20; // 需要的删除操作数
        // 用删除操作取代部分修改操作，可以省掉多少修改操作？
        int deleteOp = needDelete;
        if (deleteOp <= type[0]) {
            modifyOp -= deleteOp;
        } else {
            modifyOp -= type[0];
            deleteOp -= type[0];
            // len%3==1这类子串要省掉type[1]个修改，需要2*type[1]个删除
            if (deleteOp <= 2 * type[1]) {
                modifyOp -= deleteOp / 2;
            } else {
                modifyOp -= type[1];
                deleteOp -= 2 * type[1];
                // 剩下的deleteOp都作用在len%3==2这类子串上
                modifyOp -= deleteOp / 3;    
            }
        }
        // modifyOp可以同时解决needLUD问题，所以用 max(modifyOp, needLUD)
        return needDelete + max(modifyOp, needLUD);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
