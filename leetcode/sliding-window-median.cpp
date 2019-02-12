//
//  sliding-window-median
//  https://leetcode.com/problems/sliding-window-median/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MedianQueue {
    // 最大堆负责左半，最小堆负责右半
    // 因为c++的priority_queue没法随意删除元素，用multiset替代
    multiset<int, greater<int>> lo;
    multiset<int> hi;

    void moveOneToLo() {
        lo.insert(*hi.begin());
        hi.erase(hi.begin());
    }
    
    void moveOneToHi() {
        hi.insert(*lo.begin());
        lo.erase(lo.begin());        
    }
public:
    // 保证lo比hi大1或等大
    void push(int num) {
        if (lo.size() > hi.size()) {
            lo.insert(num);
            moveOneToHi();
        } else {
            hi.insert(num);
            moveOneToLo();
        }
    }
    
    void remove(int num) {
        if (num <= *lo.begin()) {
            lo.erase(lo.find(num));
            if (lo.size() < hi.size()) {
                moveOneToLo();
            }
        } else {
            hi.erase(hi.find(num));
            if (lo.size() - hi.size() > 1) {
                moveOneToHi();
            }
        }
    }
    
    double median() {
        if (lo.size() > hi.size()) {
            return *lo.begin();
        } else {
            return ((double)*lo.begin() + *hi.begin()) / 2;
        }
    }
};

class Solution {
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        MedianQueue mq;
        for (int i = 0; i < k; i++) {
            mq.push(nums[i]);
        }
        
        vector<double> ans;
        ans.push_back(mq.median());
        for (int i = k; i < nums.size(); i++) {
            mq.push(nums[i]);
            mq.remove(nums[i-k]);
            ans.push_back(mq.median());
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
