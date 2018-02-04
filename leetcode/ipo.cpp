//
//  ipo
//  https://leetcode.com/problems/ipo/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // 先把所有项目索引都放到优先队列projects，projects是关于Capital的最小堆
        auto cmpMinCapital = [&Capital](int a, int b) {
            return Capital[a] > Capital[b];
        };
        priority_queue<int, vector<int>, decltype(cmpMinCapital)> projects(cmpMinCapital);
        for (int i = 0; i < Capital.size(); i++) {
            projects.push(i);
        }
        // 再将capital需求<=W的都放到优先队列pickable，从中取profit最大的执行
        auto cmpMaxProfit = [&Profits](int a, int b) {
            return Profits[a] < Profits[b];
        };
        priority_queue<int, vector<int>, decltype(cmpMaxProfit)> pickable(cmpMaxProfit);
        while (k) {
            while (!projects.empty() && Capital[projects.top()] <= W) {
                pickable.push(projects.top());
                projects.pop();
            }
            if (pickable.empty()) break;

            W += Profits[pickable.top()];
            pickable.pop();
            k--;
        }
        return W;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
