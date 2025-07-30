//
//  brick-wall
//  https://leetcode.com/problems/brick-wall/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <map>

using namespace std;

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        // 记录各行砖缝位置，看哪个位置砖缝最多
        map<long, int> cnt;
        int maxcnt = 0;
        for (auto& line : wall) {
            long pos = 0;
            for (int j = 0; j < line.size() - 1; j++) {
                pos += line[j];
                cnt[pos]++;
                maxcnt = max(maxcnt, cnt[pos]);
            }
        }
        return wall.size() - maxcnt;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
