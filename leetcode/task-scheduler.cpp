//
//  task-scheduler
//  https://leetcode.com/problems/task-scheduler/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for (char t : tasks) count[t - 'A']++;

        int maxCnt = INT_MIN;
        int tasksWithMaxCnt = 0;
        for (int cnt : count) {
            if (cnt > maxCnt) {
                maxCnt = cnt;
                tasksWithMaxCnt = 1;
            } else if (cnt == maxCnt) {
                tasksWithMaxCnt++;
            }
        }

        return max((maxCnt - 1) * (1 + n) + tasksWithMaxCnt, (int)tasks.size());
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
