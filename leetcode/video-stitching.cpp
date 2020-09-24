//
//  video-stitching
//  https://leetcode.com/problems/video-stitching/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int videoStitching(vector<vector<int>>& clips, int T) {
        const int N = clips.size();
        sort(begin(clips), end(clips));
        int ans = 0;
        int sofar = 0; // 已覆盖[0..sofar]时间
        int i = 0, extend = 0; // 尝试扩展到extend时间
        while (sofar < T) {
            while (i < N && clips[i][0] <= sofar) {
                extend = max(extend, clips[i][1]); // 选最长的
                i++;
            }
            if (extend == sofar) return -1;
            sofar = extend;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
