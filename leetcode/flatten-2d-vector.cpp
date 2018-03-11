//
//  flatten-2d-vector
//  https://leetcode.com/problems/flatten-2d-vector/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Vector2D {
    vector<vector<int>>::iterator rowIt, rowEndIt;
    vector<int>::iterator colIt;
public:
    Vector2D(vector<vector<int>>& vec2d) {
        rowIt = vec2d.begin(), rowEndIt = vec2d.end();
        if (rowIt != rowEndIt) colIt = rowIt->begin();
    }

    int next() {
        return *colIt++;
    }

    bool hasNext() {
        while (rowIt != rowEndIt) {
            if (colIt != rowIt->end()) return true;
            rowIt++;
            if (rowIt != rowEndIt) colIt = rowIt->begin();
        }
        return false;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
