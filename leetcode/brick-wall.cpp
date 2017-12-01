//
//  brick-wall
//  https://leetcode.com/problems/brick-wall/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 记录各行砖缝位置，看哪个位置砖缝最多
        map<int, int> count;
        int maxCount = 0;
        for (auto &line : wall) {
            int pos = 0;
            for (int j = 0; j < line.size() - 1; j++) {
                pos += line[j];
                count[pos]++;
                maxCount = max(maxCount, count[pos]);
            }
        }
        return wall.size() - maxCount;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
