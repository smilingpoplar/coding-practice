//
//  construct-the-rectangle
//  https://leetcode.com/problems/construct-the-rectangle/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
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
