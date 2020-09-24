//
//  find-median-from-data-stream
//  https://leetcode.com/problems/find-median-from-data-stream/
//
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
        return lo.top();
    }
};

/*
class MedianFinder {
    map<int, int> counter;
    int totalCnt = 0;
public:
    MedianFinder() {
    }
    
    void addNum(int num) {
        counter[num]++;
        totalCnt++;
    }
    
    double findMedian() {
        // 如：5个的第3个，4个的第2个
        int medianCnt = totalCnt / 2 + totalCnt % 2;
        int searchCnt = 0, median = 0;
        auto it = counter.begin();
        while (searchCnt < medianCnt) {
            median = it->first;
            searchCnt += it->second;
            it++;
        }
        if (totalCnt % 2 == 1) return median;
        
        int median1 = median;
        while (searchCnt < medianCnt + 1) {
            median = it->first;
            searchCnt += it->second;
            it++;
        }
        return (median1 + median) * 0.5;
    }
};
*/

int main(int argc, const char * argv[]) {
    MedianFinder obj = new MedianFinder();
    obj.addNum(num);
    double param_2 = obj.findMedian();
    return 0;
}
