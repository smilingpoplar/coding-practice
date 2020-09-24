//
//  escape-the-ghosts
//  https://leetcode.com/problems/escape-the-ghosts/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool escapeGhosts(vector<vector<int>>& ghosts, vector<int>& target) {
        vector<int> pacman = {0, 0};
        int distPacman = dist(pacman, target);
        for (auto &ghost : ghosts) {
            if (dist(ghost, target) <= distPacman) return false;
        }
        return true;
    }
    
    int dist(vector<int> &from, vector<int> &target) {
        return abs(from[0] - target[0]) + abs(from[1] - target[1]);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
