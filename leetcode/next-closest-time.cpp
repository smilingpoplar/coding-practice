//
//  next-closest-time
//  https://leetcode.com/problems/next-closest-time/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string nextClosestTime(string time) {
        // 都化成分钟数，模拟时间前进1分钟
        auto colon = time.find(":");
        int curr = stoi(time.substr(0, colon)) * 60 + stoi(time.substr(colon + 1));

        const int dayMins = 24 * 60;
        for (int i = 1; i <= dayMins; i++) {
            int minutes = (curr + i) % dayMins;
            auto next = getNextTime(minutes, time);
            if (!next.empty()) return next;
        }
        return "";
    }
    
    string getNextTime(int minutes, const string &digits) {
        const int digitMins[4] = {600, 60, 10, 1};

        string ans;
        for (int j = 0; j < 4; j++) {
            char c = '0' + minutes / digitMins[j];
            minutes %= digitMins[j];
            if (digits.find(c) == string::npos) return "";

            if (j == 2) ans += ":";
            ans += c;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
