//
//  kth-largest-element-in-a-stream
//  https://leetcode.com/problems/kth-largest-element-in-a-stream/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class KthLargest {
public:
    KthLargest(int k, vector<int> nums) {
        this->k = k;
        for (int num : nums) add(num);
    }
    
    int add(int val) {
        pq.push(val);
        if (pq.size() > k) pq.pop();
        return pq.top();
    }
private:
    priority_queue<int, vector<int>, greater<int>> pq; // 最小堆
    int k;
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest obj = new KthLargest(k, nums);
 * int param_1 = obj.add(val);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
