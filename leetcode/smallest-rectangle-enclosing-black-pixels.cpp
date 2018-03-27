//
//  smallest-rectangle-enclosing-black-pixels
//  https://leetcode.com/problems/smallest-rectangle-enclosing-black-pixels/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        // dfs或bfs的解法不必再说，这题还可用二分搜索解。
        // 想象把一个列向下投影成一个点，列中有1时投影成1。
        // 这样，整个区域向下投影成一段连续的1，找这段1的左右端；
        // 同理，整个区域向右投影成一段连续的1，找这段1的上下端。
        if (image.empty()) return 0;
        const int M = image.size();
        const int N = image[0].size();
        int left = search(true, 0, y + 1, true, image, 0, M);
        int right = search(true, y, N, false, image, 0, M);
        int top = search(false, 0, x + 1, true, image, left, right);
        int bottom = search(false, x, M, false, image, left, right);
        return (right - left) * (bottom - top);
    }
    
    // 在投影行的[start,end)列中找，或在投影列的[start,end)行中找
    // searchFirstOne：为真时在投影里找第一个1，为假时找第一个0
    // range1,range2：被投影压缩的那个维度
    int search(bool projToRow, int start, int end, bool searchFirstOne,
               vector<vector<char>> &image, int range1, int range2) {
        while (start < end) {
            int mid = start + (end - start) / 2;
            // 先根据searchFirstOne写出两分支，再简化成下面
            if (isOneInProj(projToRow, mid, image, range1, range2) == searchFirstOne) {
                end = mid;
            } else {
                start = mid + 1;
            }
        }
        return end;
    }
    
    bool isOneInProj(bool projToRow, int idxInProj, vector<vector<char>> &image,
                     int range1, int range2) {
        for (int i = range1; i < range2; i++) {
            if (projToRow) {
                if (image[i][idxInProj] == '1') return true;                
            } else {
                if (image[idxInProj][i] == '1') return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
