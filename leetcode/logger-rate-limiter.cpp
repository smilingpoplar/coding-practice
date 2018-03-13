//
//  logger-rate-limiter
//  https://leetcode.com/problems/logger-rate-limiter/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Logger {
    static const int SECONDS = 10; // 只保留最近10秒的消息，按时间分桶
    int timestamps[SECONDS] = { 0 };
    set<string> msgs[SECONDS];
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        int idx = timestamp % SECONDS;
        if (timestamps[idx] != timestamp) { // 对应桶无效了
            timestamps[idx] = timestamp;
            msgs[idx].clear();
        }
        // 查找所有桶
        for (int i = 0; i < SECONDS; i++) {
            if (timestamp - timestamps[i] <= SECONDS && msgs[i].count(message)) return false;
        }
        msgs[idx].insert(message); // 更新对应桶
        return true;
    }
};

/**
 * Your Logger object will be instantiated and called as such:
 * Logger obj = new Logger();
 * bool param_1 = obj.shouldPrintMessage(timestamp,message);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
