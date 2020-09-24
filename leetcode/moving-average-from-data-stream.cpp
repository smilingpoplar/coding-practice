//
//  moving-average-from-data-stream
//  https://leetcode.com/problems/moving-average-from-data-stream/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class MovingAverage {
    queue<int> q;
    int maxSize;
    double sum = 0;
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        maxSize = size;
    }
    
    double next(int val) {
        if (q.size() == maxSize) {
            sum -= q.front();
            q.pop();
        }
        sum += val;
        q.push(val);
        return sum / q.size();
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
