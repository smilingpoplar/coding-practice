//
//  daily-temperatures
//  https://leetcode.com/problems/daily-temperatures/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        const int N = T.size();
        vector<int> ans(N, 0);
        stack<int> stk;
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && T[i] > T[stk.top()]) {
                int pop = stk.top(); stk.pop();
                ans[pop] = i - pop;
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
