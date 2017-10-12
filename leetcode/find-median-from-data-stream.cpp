//
//  find-median-from-data-stream
//  https://leetcode.com/problems/find-median-from-data-stream/
//
//  Created by smilingpoplar on 17/10/12.
//  Copyright (c) 2017年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class MedianFinder {
    priority_queue<int> lo; // 左半边最大堆
    priority_queue<int, vector<int>, greater<int>> hi; // 右半边最小堆
public:
    /** initialize your data structure here. */
    MedianFinder() {
    }
    // 保持左半堆与右半堆等大或大1
    void addNum(int num) {
        if (lo.size() == hi.size()) {
            hi.push(num);
            lo.push(hi.top());
            hi.pop();
        } else { // 左半堆大1
            lo.push(num);
            hi.push(lo.top());
            lo.pop();
        }
    }
    
    double findMedian() {
        if (lo.empty()) return 0;
        if (lo.size() == hi.size()) return (lo.top() + hi.top()) * 0.5;
        else return lo.top();
    }
};

int main(int argc, const char * argv[]) {
    MedianFinder obj = new MedianFinder();
    obj.addNum(num);
    double param_2 = obj.findMedian();
    return 0;
}
