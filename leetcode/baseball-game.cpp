//
//  baseball-game
//  https://leetcode.com/problems/baseball-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stk;
        for (string &op : ops) {
            if (op == "+") {
                int a = stk.top(); stk.pop();
                int b = stk.top(); stk.push(a);
                stk.push(a + b);
            } else if (op == "D") {
                int a = stk.top();
                stk.push(a * 2);
            } else if (op == "C") {
                stk.pop();
            } else { // integer
                stk.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!stk.empty()) {
            sum += stk.top();
            stk.pop();
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
