//
//  logger-rate-limiter
//  https://leetcode.com/problems/logger-rate-limiter/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
// 解法同：https://leetcode.com/problems/design-hit-counter/
class Logger {
    // 按时间分桶，对应的times[i]和msgs[i]构成逻辑上的buckets[i]，用循环数组方式
    const int SECONDS = 10; // 只保留最近10s的消息
    vector<int> times;
    vector<set<string>> msgs;
public:
    Logger() : times(SECONDS, 0), msgs(SECONDS) {
    }
    
    bool shouldPrintMessage(int timestamp, string message) {
        int idx = timestamp % SECONDS;
        if (times[idx] != timestamp) { // 对应桶已无效
            times[idx] = timestamp;
            msgs[idx].clear();
        }
        // 查找所有桶，看10s内是否输出过该消息
        for (int i = 0; i < times.size(); i++) {
            if (timestamp - times[i] < SECONDS && msgs[i].count(message)) return false;
        }
        msgs[idx].insert(message); // 更新对应桶
        return true;
    }
};
*/

// 因为时间递增，用队列
class Logger {
    const int SECONDS = 10; // 只保留最近10s的消息
    queue<pair<int, string>> q;
    set<string> msgs; // 判断重复消息
public:
    /** Initialize your data structure here. */
    Logger() {
    }
    
    /** Returns true if the message should be printed in the given timestamp, otherwise returns false.
        If this method returns false, the message will not be printed.
        The timestamp is in seconds granularity. */
    bool shouldPrintMessage(int timestamp, string message) {
        while (!q.empty() && timestamp - q.front().first >= SECONDS) {
            msgs.erase(q.front().second);
            q.pop();
        }
        // 剩下的都是10s内
        if (msgs.count(message)) return false;
        q.push({timestamp, message});
        msgs.insert(message);
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
