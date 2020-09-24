//
//  optimal-division
//  https://leetcode.com/problems/optimal-division/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string optimalDivision(vector<int>& nums) {
        // 答案一定是 a/(b/c/...)
        if (nums.empty()) return "";
        const int N = nums.size();
        ostringstream oss;
        if (N == 1) {
            oss << nums[0];
        } else if (N == 2) {
            oss << nums[0] << "/" << nums[1];
        } else {
            oss << nums[0] << "/(" << nums[1];
            for (int i = 2; i < N; i++) oss << "/" << nums[i];
            oss << ")";   
        }
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
