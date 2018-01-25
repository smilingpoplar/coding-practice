//
//  daily-temperatures
//  https://leetcode.com/problems/daily-temperatures/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        const int N = temperatures.size();
        vector<int> ans(N, 0);
        stack<int> S;
        for (int i = 0; i < N; i++) {
            while (!S.empty() && temperatures[i] > temperatures[S.top()]) {
                int top = S.top();
                S.pop();
                ans[top] = i - top;                
            }
            S.push(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
