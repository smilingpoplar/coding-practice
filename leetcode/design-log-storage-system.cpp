//
//  design-log-storage-system
//  https://leetcode.com/problems/design-log-storage-system/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class LogSystem {
    map<string, int> log; // timestamp=>id
    
    // 时间串直接比较来判断先后，"比较粒度"就是前n个字符
    unordered_map<string, int> granu = {{"Year", 4}, {"Month", 7}, {"Day", 10}, 
                                        {"Hour", 13}, {"Minute", 16}, {"Second", 19}};
    string paddingLow = "2000:00:00:00:00:00";
    string paddingHigh = "2017:12:31:23:59:59";
public:
    LogSystem() {
    }
    
    void put(int id, string timestamp) {
        log[timestamp] = id;
    }
    
    vector<int> retrieve(string s, string e, string gra) {
        auto len = granu[gra];
        auto start = s.substr(0, len) + paddingLow.substr(len);
        auto end = e.substr(0, len) + paddingHigh.substr(len);
        auto lower = log.lower_bound(start);
        auto upper = log.upper_bound(end);
        
        vector<int> ans;
        for (auto it = lower; it != upper; it++) {
            ans.push_back(it->second);
        }
        return ans;
    }
};

/**
 * Your LogSystem object will be instantiated and called as such:
 * LogSystem obj = new LogSystem();
 * obj.put(id,timestamp);
 * vector<int> param_2 = obj.retrieve(s,e,gra);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
