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
        vector<int> count(26, 0);
        for (char t : tasks) {
            count[t - 'A']++;
        }
        int maxC = INT_MIN;
        int countMaxC = 0;
        for (int c : count) {
            if (c > maxC) {
                maxC = c;
                countMaxC = 1;
            } else if (c == maxC) {
                countMaxC++;
            }
        }

        return max((maxC - 1) * (n + 1) + countMaxC, (int)tasks.size());
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
