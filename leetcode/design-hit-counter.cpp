//
//  design-hit-counter
//  https://leetcode.com/problems/design-hit-counter/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class HitCounter {
    // 按时间分桶，times[i]和hits[i]构成逻辑上的buckets[i]，用循环数组方式
    const int SECONDS = 300;
    vector<int> times;
    vector<int> hits;
public:
    /** Initialize your data structure here. */
    HitCounter() : times(SECONDS, 1), hits(SECONDS, 0) {
        
    }
    
    /** Record a hit.
        @param timestamp - The current timestamp (in seconds granularity). */
    void hit(int timestamp) {
        int idx = timestamp % SECONDS;
        if (times[idx] != timestamp) { // 对应的桶已无效
            times[idx] = timestamp;
            hits[idx] = 0;
        }
        hits[idx]++;
    }
    
    /** Return the number of hits in the past 5 minutes.
        @param timestamp - The current timestamp (in seconds granularity). */
    int getHits(int timestamp) {
        int ans = 0;
        for (int i = 0; i < times.size(); i++) {
            if (timestamp - times[i] < SECONDS) ans += hits[i];
        }
        return ans;
    }
};

/**
 * Your HitCounter object will be instantiated and called as such:
 * HitCounter obj = new HitCounter();
 * obj.hit(timestamp);
 * int param_2 = obj.getHits(timestamp);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
