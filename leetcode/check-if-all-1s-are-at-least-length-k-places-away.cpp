//
//  check-if-all-1s-are-at-least-length-k-places-away
//  https://leetcode.com/problems/check-if-all-1s-are-at-least-length-k-places-away/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        const int N = nums.size();
        int last = - k - 1;
        for (int i = 0; i < N; i++) {
            if (nums[i] == 1) {
                if (i - last - 1 < k) return false;
                last = i;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
