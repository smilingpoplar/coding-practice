//
//  find-all-duplicates-in-an-array
//  https://leetcode.com/problems/find-all-duplicates-in-an-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        // 把数x当作下标（1-based），将nums[x-1]标记为负数
        vector<int> ans;
        for (int num : nums) {
            int x = abs(num);
            if (nums[x-1] < 0) ans.push_back(x);
            else nums[x-1] *= -1;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
