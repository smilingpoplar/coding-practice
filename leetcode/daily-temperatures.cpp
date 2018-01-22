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
        vector<int> stack;
        for (int i = 0; i < N; ++i) {
            while (!stack.empty() && temperatures[i] > temperatures[stack.back()]) {
                int top = stack.back();
                stack.pop_back();
                ans[top] = i - top;                
            }
            stack.push_back(i);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
