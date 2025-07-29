//
//  single-number
//  https://leetcode.com/problems/single-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (auto num : nums) {
            ans ^= num;
        }
        return ans;
    }
};

/*
class Solution {
public:
    // O(logN)，二分
    int singleElement(vector<int>& v) {
        // 第一个 v[mid]!=v[mid^1] 的位置
        int lo = -1, hi = v.size();
        while (lo + 1 < hi) {
            int mid = lo + (hi - lo) / 2;
            if (v[mid] != v[mid ^ 1]) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return v[hi];
    }
};
*/

int main(int argc, const char* argv[]) {
    vector<int> nums = {3, 3, 4, 5, 5};
    Solution solution;
    cout << solution.singleNumber(nums);

    return 0;
}
