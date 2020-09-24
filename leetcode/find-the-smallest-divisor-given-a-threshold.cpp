//
//  find-the-smallest-divisor-given-a-threshold
//  https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 0, u = 1e6 + 1;
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            if (enough(m, nums, threshold)) {
                u = m;
            } else {
                l = m;
            }
        }
        return u;
    }
    
    // 二分搜索条件enough(m)表示 计算所得和<=threshold
    bool enough(int m, vector<int>& nums, int threshold) {
        int sum = 0;
        for (int num : nums) {
            sum += ceil((double)num / m);
        }
        return sum <= threshold;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
