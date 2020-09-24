//
//  array-nesting
//  https://leetcode.com/problems/array-nesting/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        // 类似找最大连通子图，nums[i]表示i=>nums[i]有边
        const int N = nums.size();
        vector<bool> visited(N, false);
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (visited[i]) continue;
            int j = i; // 从i开始新群
            int count = 1;
            while (nums[j] != i) {
                visited[j] = true;
                count++;
                j = nums[j];
            }
            ans = max(ans, count);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
