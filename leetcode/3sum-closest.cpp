//
//  3sum-closest
//  https://leetcode.com/problems/3sum-closest/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        const int N = nums.size();
        if (N < 3) return INT_MAX;
        sort(nums.begin(), nums.end()); // 先排序再两指针
        
        int minDist = INT_MAX, ans;
        for (int a = 0; a < N - 2; a++) {
            int b = a + 1, c = N - 1;
            while (b < c) {
                int sum  = nums[a] + nums[b] + nums[c];
                int dist = abs(sum - target);
                if (dist < minDist) {
                    minDist = dist;
                    ans = sum;
                }
                
                if (sum == target) {
                    return sum;
                } else if (sum < target) {
                    b++;
                } else {
                    c--;
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {-1, 2, 1, -4};
    int target = 1;
    Solution solution;
    cout << solution.threeSumClosest(nums, target);
    
    return 0;
}
