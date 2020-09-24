//
//  max-chunks-to-make-sorted
//  https://leetcode.com/problems/max-chunks-to-make-sorted/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 若leftMax[i]==i，则在i后可断开左右
        int ans = 0;
        int leftMax = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            leftMax = max(leftMax, arr[i]);
            if (leftMax == i) ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
