//
//  max-chunks-to-make-sorted
//  https://leetcode.com/problems/max-chunks-to-make-sorted/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // arr[0..i]是[0..i]的排列，则新开个chunk
        int ans = 0;
        int leftMax = INT_MIN;
        for (int i = 0; i < arr.size(); ++i) {
            leftMax = max(leftMax, arr[i]);
            if (i == leftMax) ++ans;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
