//
//  zigzag-conversion
//  https://leetcode.com/problems/zigzag-conversion/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        // 观察numRows不同取值的例子，一个zigzag的字符数是2*numRows-2
        if (numRows == 1) return s;
        const int zigzag = 2 * numRows - 2;
        string result;
        for (int i = 0; i < numRows; i++) {
            for (int j = i; j < s.size(); j += zigzag) {
                result += s[j];
                if (i == 0 || i == numRows - 1) continue;
                int index = j + zigzag - 2 * i;
                if (index < s.size()) result += s[index];
            }
        }
        return result;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.convert("PAYPALISHIRING", 3);
    
    return 0;
}
