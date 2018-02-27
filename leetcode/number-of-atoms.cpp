//
//  number-of-atoms
//  https://leetcode.com/problems/number-of-atoms/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    string countOfAtoms(string formula) {
        int pos = 0;
        auto count = parse(formula, pos);
        ostringstream oss;
        for (auto &e : count) {
            oss << e.first;
            if (e.second > 1) oss << e.second;
        }
        return oss.str();
    }
    
    // 解析一层括号
    map<string, int> parse(const string &formula, int &pos) {
        const int N = formula.size();
        map<string, int> count;
        while (pos < N && formula[pos] != ')') {
            if (formula[pos] == '(') {
                pos++; // (
                auto paren = parse(formula, pos);
                int num = parseNum(formula, pos);
                for (auto &e : paren) { 
                    count[e.first] += e.second * num;                    
                }
            } else {
                int start = pos;
                pos++; // upper case
                while (pos < N && islower(formula[pos])) pos++;
                auto name = formula.substr(start, pos - start);
                int num = parseNum(formula, pos);
                count[name] += num;
            }
        }    
        if (pos < N) pos++; // )
        return count;
    }
    
    int parseNum(const string &formula, int &pos) {
        int start = pos;
        while (pos < formula.size() && isdigit(formula[pos])) pos++;
        if (pos == start) return 1;
        return stoi(formula.substr(start, pos - start));
    }
};
*/

class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push({});
        
        const int N = formula.size();
        int pos = 0;
        while (pos < N) {
            if (formula[pos] == '(') {
                pos++; // (
                stk.push({});
            } else if (formula[pos] == ')') {
                pos++; // )
                auto top = stk.top(); stk.pop();
                int num = parseNum(formula, pos);
                for (auto &e : top) {
                    stk.top()[e.first] += e.second * num;
                }
            } else {
                int start = pos;
                pos++; // upper case
                while (pos < N && islower(formula[pos])) pos++;
                auto name = formula.substr(start, pos - start);
                int num = parseNum(formula, pos);
                stk.top()[name] += num;
            }
        }
        
        ostringstream oss;
        for (auto &e : stk.top()) {
            oss << e.first;
            if (e.second > 1) oss << e.second;
        }
        return oss.str();
    }
    
    int parseNum(const string &formula, int &pos) {
        int start = pos;
        while (pos < formula.size() && isdigit(formula[pos])) pos++;
        if (pos == start) return 1;
        return stoi(formula.substr(start, pos - start));
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
