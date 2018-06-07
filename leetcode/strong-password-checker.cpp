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
    // https://leetcode.com/problems/strong-password-checker/discuss/91002/JAVA-Easy-Solution-with-explanation
    int strongPasswordChecker(string s) {
        const int N = s.size();
        bool hasLower = false, hasUpper = false, hasDigit = false;
        int replaceOp = 0;
        // 设重复串长r，r>=3。
        // repeatChars[0]表示r%3==0的重复串个数，它们用1个删除取代最后1个替换，比如 aa#aa#   => aa#aa
        // repeatChars[1]表示r%3==1的重复串个数，它们用2个删除取代最后1个替换，比如 aa#aa#a  => aa#aa
        // repeatChars[2]表示r%3==2的重复串个数，它们用3个删除取代最后1个替换，比如 aa#aa#aa => aa#aa
        vector<int> repeatChars(3, 0);
        for (int i = 0, j; i < N; i = j) {
            if(islower(s[i])) hasLower = true;
            else if(isupper(s[i])) hasUpper = true;
            else if(isdigit(s[i])) hasDigit = true;
            
            j = i + 1;
            while (j < N && s[j] == s[i]) j++;
            int r = j - i;
            if (r >= 3) {
                replaceOp += r / 3;
                repeatChars[r % 3]++;
            }                
        }
        
        int needLUD = 3 - (hasLower + hasUpper + hasDigit);
        if (N < 6) return max(6 - N, needLUD); // 只需插入操作
        if (N <= 20) return max(replaceOp, needLUD); // 只需替换操作
        const int deleteOp = N - 20; // 需要这么多删除操作
        int needDelete = deleteOp;
        // 这些删除操作可以节省多少替换操作
        if (needDelete <= repeatChars[0]) {
            replaceOp -= needDelete;
        } else {
            needDelete -= repeatChars[0];
            if (needDelete <= 2 * repeatChars[1]) {
                replaceOp -= repeatChars[0] + needDelete / 2;
            } else {
                needDelete -= 2 * repeatChars[1];
                replaceOp -= repeatChars[0] + repeatChars[1] + needDelete / 3;    
            }
        }
        return deleteOp + max(replaceOp, needLUD);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
