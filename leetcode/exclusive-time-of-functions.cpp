//
//  exclusive-time-of-functions
//  https://leetcode.com/problems/exclusive-time-of-functions/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    struct Log {
        int funcId;
        bool isStart;
        int timestamp;
    };
public:
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        vector<int> ans(n, 0);
        stack<Log> stk;
        for (auto &str : logs) {
            auto log = parse(str);
            if (log.isStart) {
                stk.push(log);
            } else {
                auto &curr = stk.top();  stk.pop();
                int time = log.timestamp - curr.timestamp + 1;
                ans[log.funcId] += time;
                if (!stk.empty()) ans[stk.top().funcId] -= time;
            }            
        }
        return ans;
    }
    
    Log parse(string &str) {
        istringstream iss(str);
        string s;
        getline(iss, s, ':');
        int funcId = stoi(s);
        getline(iss, s, ':');
        bool isStart = s == "start";
        getline(iss, s, ':');
        int timestamp = stoi(s);
        return { funcId, isStart, timestamp };
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
