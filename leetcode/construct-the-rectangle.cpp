//
//  construct-the-rectangle
//  https://leetcode.com/problems/construct-the-rectangle/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> constructRectangle(int area) {
        int w = sqrt(area);
        while (area % w != 0)
            w--;
        return { area / w, w };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
