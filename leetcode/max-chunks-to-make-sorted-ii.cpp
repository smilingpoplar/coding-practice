//
//  max-chunks-to-make-sorted-ii
//  https://leetcode.com/problems/max-chunks-to-make-sorted-ii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
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
};

int main(int argc, const char * argv[]) {    
    return 0;
}
