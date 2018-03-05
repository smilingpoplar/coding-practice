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
        int replaces = 0;
        // 设重复串长r，r>=3。
        // deleteLastRepeatChars[0]表示r%3==0的重复串个数，它们可用1个删除取代最后1个替换，比如aa#aa#   => aa#aa
        // deleteLastRepeatChars[1]表示r%3==1的重复串个数，它们可用2个删除取代最后1个替换，比如aa#aa#a  => aa#aa
        // deleteLastRepeatChars[2]表示r%3==2的重复串个数，它们可用3个删除取代最后1个替换，比如aa#aa#aa => aa#aa
        vector<int> deleteLastRepeatChars(3, 0);
        for (int i = 0, j; i < N; i = j) {
            if(islower(s[i])) hasLower = true;
            else if(isupper(s[i])) hasUpper = true;
            else if(isdigit(s[i])) hasDigit = true;
            
            j = i + 1;
            while (j < N && s[j] == s[i]) j++;
            int r = j - i;
            if (r >= 3) {
                replaces += r / 3;
                deleteLastRepeatChars[r % 3]++;
            }                
        }
        
        int needLUD = 3 - (hasLower + hasUpper + hasDigit);
        if (N < 6) return max(6 - N, needLUD); // 只需插入操作
        if (N <= 20) return max(replaces, needLUD); // 只需替换操作
        const int deletes = N - 20;
        if (deletes <= deleteLastRepeatChars[0]) {
            replaces -= deletes;
        } else {
            int toDelete = deletes - deleteLastRepeatChars[0];
            if (toDelete <= 2 * deleteLastRepeatChars[1]) {
                replaces -= deleteLastRepeatChars[0] + toDelete / 2;
            } else {
                toDelete -= 2 * deleteLastRepeatChars[1];
                replaces -= deleteLastRepeatChars[0] + deleteLastRepeatChars[1] + toDelete / 3;    
            }
        }
        return deletes + max(replaces, needLUD);        
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
