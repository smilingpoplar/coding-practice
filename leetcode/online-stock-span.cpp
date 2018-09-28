//
//  online-stock-span
//  https://leetcode.com/problems/online-stock-span/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class StockSpanner {
    stack<pair<int, int>> stk; // (val,idx)
    int curr = 0;
public:
    StockSpanner() {
    }
    
    int next(int price) {
        // 找<=price的最近连续天数
        // 左边<=price的数不断弹出，直到>price的位置prev，则span=curr-prev
        // 栈中将保留递减序列，对应找波谷、下一个更大的数
        while (!stk.empty() && price >= stk.top().first) {
            stk.pop();
        }
        int prev = stk.empty() ? -1 : stk.top().second;
        stk.push({price, curr});
        return curr++ - prev;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
