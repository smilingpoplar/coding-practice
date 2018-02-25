//
//  minimum-time-difference
//  https://leetcode.com/problems/minimum-time-difference/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> minutes;
        for (auto &time : timePoints) {
            minutes.push_back(getMinute(time)); // 全转化成分钟数
        }
        sort(minutes.begin(), minutes.end());
        minutes.push_back(minutes.front() + 60 * 24); // 最后和最初时间要比较差值
        
        int ans = INT_MAX;
        for (int i = 1; i < minutes.size(); i++) {
            ans = min(ans, minutes[i] - minutes[i-1]);
        }
        return ans;
    }
    
    int getMinute(const string &time) {
        return stoi(time.substr(0, 2)) * 60 + stoi(time.substr(3, 2));
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
