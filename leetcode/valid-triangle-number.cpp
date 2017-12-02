//
//  valid-triangle-number
//  https://leetcode.com/problems/valid-triangle-number/
//
//  Created by smilingpoplar on 17/12/02.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int N = (int)nums.size();
        int count = 0;
        for (int i = 0; i < N - 2; i++) {
            if (nums[i] == 0) continue;
            for (int j = i + 1; j < N - 1; j++) {
                int k = j + 1;
                while (k < N && nums[i] + nums[j] > nums[k]) {
                    k++;
                }
                count += k - j - 1;
            }
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
