//
//  max-chunks-to-make-sorted-ii
//  https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // arr[i]在排序后该在的位置上，leftMax[i]<=rightMin[i+1]，则加个chunk
        const int N = arr.size();
        vector<int> rightMin(N, INT_MAX);
        rightMin[N-1] = arr[N-1];
        for (int i = N-2; i >= 0; --i) {
            rightMin[i] = min(arr[i], rightMin[i+1]);
        }
        int ans = 1;
        int leftMax = INT_MIN;
        for (int i = 0; i < N-1; ++i) {
            leftMax = max(leftMax, arr[i]);
            if (leftMax <= rightMin[i+1]) ++ans;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}