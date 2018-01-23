//
//  baseball-game
//  https://leetcode.com/problems/baseball-game/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> stack;
        for (string &op : ops) {
            if (op == "+") {
                int a = stack.top(); 
                stack.pop();
                int b = stack.top(); 
                stack.push(a);
                stack.push(a + b);
            } else if (op == "D") {
                int a = stack.top();
                stack.push(a * 2);
            } else if (op == "C") {
                stack.pop();
            } else { // integer
                stack.push(stoi(op));
            }
        }
        
        int sum = 0;
        while (!stack.empty()) {
            sum += stack.top();
            stack.pop();
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
