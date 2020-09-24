//
//  similar-rgb-color
//  https://leetcode.com/problems/similar-rgb-color/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string similarRGB(string color) {
        return "#" + similarColor(color.substr(1, 2))
            + similarColor(color.substr(3, 2))
            + similarColor(color.substr(5, 2));
    }
    
    string similarColor(const string &ab) {
        const string mapping = "0123456789abcdef";
        // #ab要变成#xx，#xx=16*x+x=17x，所以要找最接近#ab的17的倍数
        int num = stoi(ab, NULL, 16);
        int x = (num + 8) / 17; // "四舍五入"
        return string(2, mapping[x]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
