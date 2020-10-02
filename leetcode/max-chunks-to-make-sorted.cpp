//
//  max-chunks-to-make-sorted
//  https://leetcode.com/problems/max-chunks-to-make-sorted/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        // 数组是[1,n]的排列，若maxL[i]==i，则在i后可断开左右
        int ans = 0;
        int maxL = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            maxL = max(maxL, arr[i]);
            if (maxL == i) ans++;
        }
        return ans;
    }
};

/*
int maxChunksToSorted(vector<int>& arr) {
    // maxL[i]表示arr[0..i)的最大值，minR[i]表示arr[i..]的最小值
    // maxL[i]<=minR[i]时可分
    const int N = arr.size();
    vector<int> maxL(N + 1, INT_MIN), minR(N + 1, INT_MAX);
    for (int i = 0; i < N; i++) {
        maxL[i+1] = max(maxL[i], arr[i]);
    }

    int ans = 0;
    for (int i = N - 1; i >= 0; i--) {
        minR[i] = min(minR[i+1], arr[i]);
        if (maxL[i] <= minR[i]) ans++;
    }
    return ans;
}
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
