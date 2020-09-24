//
//  flood-fill
//  https://leetcode.com/problems/flood-fill/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int oldColor = image[sr][sc];
        if (newColor != oldColor) fill(image, sr, sc, oldColor, newColor);
        return image;
    }
    
    void fill(vector<vector<int>> &image, int r, int c, int oldColor, int newColor) {
        int M = image.size(), N = image[0].size();
        if (r < 0 || r >= M || c < 0 || c >= N || image[r][c] != oldColor) return;
        image[r][c] = newColor;
        vector<vector<int>> dirs = { {-1,0}, {0,1}, {1,0}, {0,-1} };
        for (auto &dir : dirs) {
            int nr = r + dir[0], nc = c + dir[1];
            fill(image, nr, nc, oldColor, newColor);
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
