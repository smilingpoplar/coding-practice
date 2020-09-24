//
//  valid-square
//  https://leetcode.com/problems/valid-square/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        vector<vector<int>> p = { p1, p2, p3, p4 };
        sort(p.begin(), p.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0] || (a[0] == b[0] && a[1] < b[1]);
        });
        int side = dist(p[0], p[1]);
        return side != 0 && side == dist(p[1], p[3]) && side == dist(p[3], p[2]) && side == dist(p[2], p[0]) 
            && dist(p[0], p[3]) == dist(p[1], p[2]);
    }
    
    int dist(vector<int> &a, vector<int> &b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
