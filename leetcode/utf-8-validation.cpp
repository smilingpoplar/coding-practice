//
//  utf-8-validation
//  https://leetcode.com/problems/utf-8-validation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validUtf8(vector<int>& data) {
        int count = 0; // 需要一起验证的还有几字节
        for (auto c : data) {
            if (count == 0) {
                if ((c >> 3) == 0b11110) count = 3;
                else if ((c >> 4) == 0b1110) count = 2;
                else if ((c >> 5) == 0b110) count = 1;
                else if ((c >> 7) != 0b0) return false;
            } else {
                if ((c >> 6) != 0b10) return false;
                count--;
            }
        }
        return count == 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
