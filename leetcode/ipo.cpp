//
//  ipo
//  https://leetcode.com/problems/ipo/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        // 先把所有索引都放到关于Capital的最小堆中
        auto cmpMinCapital = [&Capital](int a, int b) { return Capital[a] > Capital[b]; };
        priority_queue<int, vector<int>, decltype(cmpMinCapital)> unselected(cmpMinCapital);
        for (int i = 0; i < Capital.size(); i++) unselected.push(i);
        // 把capital需求<=W的取出放到关于Profit的最大堆中，优先取profit最大的
        auto cmpMaxProfit = [&Profits](int a, int b) { return Profits[a] < Profits[b]; };
        priority_queue<int, vector<int>, decltype(cmpMaxProfit)> selectable(cmpMaxProfit);
        while (k) {
            while (!unselected.empty() && Capital[unselected.top()] <= W) {
                int idx = unselected.top(); unselected.pop();
                selectable.push(idx);
            }
            if (selectable.empty()) break;

            int idx = selectable.top(); selectable.pop();
            W += Profits[idx];
            k--;
        }
        return W;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
