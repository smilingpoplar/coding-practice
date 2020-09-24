//
//  shuffle-an-array
//  https://leetcode.com/problems/shuffle-an-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> origin;
public:
    Solution(vector<int> nums) {
        origin = nums;
        srand(time(NULL));
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        return origin;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> ans(origin);
        const int N = ans.size();
        for (int i = 0; i < N; i++) {
            int j = i + rand() % (N - i);
            swap(ans[i], ans[j]);
        }
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * vector<int> param_1 = obj.reset();
 * vector<int> param_2 = obj.shuffle();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
