//
//  longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit
//  https://leetcode.com/problems/longest-continuous-subarray-with-absolute-diff-less-than-or-equal-to-limit/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 子段max(A)-min(A)<=limit
        // 同时保留滑动窗口的最大最小值
        // 用deque实现单调队列，O(n)
        const int N = nums.size();
        int ans = 0, lo = 0;
        deque<int> maxq, minq;
        for (int hi = 0; hi < N; hi++) {
            while (!maxq.empty() && nums[hi] > maxq.back()) 
                maxq.pop_back();
            maxq.push_back(nums[hi]);
            
            while (!minq.empty() && nums[hi] < minq.back()) 
                minq.pop_back();
            minq.push_back(nums[hi]);
            
            while (maxq[0] - minq[0] > limit) {
                if (maxq[0] == nums[lo]) maxq.pop_front();
                if (minq[0] == nums[lo]) minq.pop_front();
                lo++;    
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};

/*
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // 子段max(A)-min(A)<=limit
        // 同时保留滑动窗口的最大最小值
        // 用multiset，O(nlogn)
        const int N = nums.size();
        multiset<int> win;
        int ans = 0, lo = 0;
        for (int hi = 0; hi < N; hi++) {
            win.insert(nums[hi]);
            while (*win.rbegin() - *win.begin() > limit) {
                win.erase(win.find(nums[lo++]));
            }
            ans = max(ans, hi - lo + 1);
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
