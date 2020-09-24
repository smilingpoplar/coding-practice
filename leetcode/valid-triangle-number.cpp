//
//  valid-triangle-number
//  https://leetcode.com/problems/valid-triangle-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = nums.size();
        int ans = 0;
        for (int k = 2; k < N; k++) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    // (i,j) & (i+1,j) & ... & (j-1,j) 都符合
                    ans += j - i;
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
