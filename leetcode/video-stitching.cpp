//
//  video-stitching
//  https://leetcode.com/problems/video-stitching/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int N = clips.size();
        sort(begin(clips), end(clips));
        int ans = 0;
        int stitch = 0; // 已覆盖[0..stitch]时间
        int i = 0, end = 0; // 尝试扩展到end时间
        while (stitch < T) {
            while (i < N && clips[i][0] <= stitch) {
                end = max(end, clips[i][1]); // 选最长的
                i++;
            }
            if (end == stitch) return -1;
            stitch = end;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
