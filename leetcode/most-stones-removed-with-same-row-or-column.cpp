//
//  most-stones-removed-with-same-row-or-column
//  https://leetcode.com/problems/most-stones-removed-with-same-row-or-column/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        // 同行或同列的要在一个并查集，这里的技巧是，
        // 把行或列作为某种资源点，石头位置连接了行列资源点，
        // 将列j+10000以区别于行i资源点
        unordered_map<int, int> uf;
        int islands = 0;
        for (auto &stone : stones) {
            unite(stone[0], stone[1] + 10000, uf, islands);
        }
        return stones.size() - islands;
    }
    
    int find(int x, unordered_map<int, int> &uf, int &islands) {
        if (!uf.count(x)) {
            uf[x] = x;
            islands++;
        }

        if (uf[x] != x) uf[x] = find(uf[x], uf, islands);
        return uf[x];
    }
    
    void unite(int x, int y, unordered_map<int, int> &uf, int &islands) {
        int px = find(x, uf, islands), py = find(y, uf, islands);
        if (px != py) {
            uf[py] = px;
            islands--;
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
