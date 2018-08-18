//
//  task-scheduler
//  https://leetcode.com/problems/task-scheduler/
//
//  Created by smilingpoplar on 17/12/03.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> cnt(26, 0);
        for (char t : tasks) cnt[t - 'A']++;

        int maxC = INT_MIN;
        int cntMaxC = 0;
        for (int c : cnt) {
            if (c > maxC) {
                maxC = c;
                cntMaxC = 1;
            } else if (c == maxC) {
                cntMaxC++;
            }
        }

        return max((maxC - 1) * (1 + n) + cntMaxC, (int)tasks.size());
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
