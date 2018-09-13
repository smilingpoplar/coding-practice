//
//  squirrel-simulation
//  https://leetcode.com/problems/squirrel-simulation/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        // 除了第一次松鼠=>坚果=>树，其他都是树=>坚果=>树
        // 算出树和所有坚果间往返的路程、松鼠第一次跑哪颗松果多花的路程最少
        int dist = 0, diff = INT_MAX;
        for (auto &nut : nuts) {
            int treeDist = getDist(tree, nut);
            dist += 2 * treeDist;
            diff = min(diff, getDist(squirrel, nut) - treeDist);
        }
        return dist + diff;
    }
    
    int getDist(vector<int> &a, vector<int>& b) {
        return abs(a[0] - b[0]) + abs(a[1] - b[1]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
