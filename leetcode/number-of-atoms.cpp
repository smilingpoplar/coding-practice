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

class Solution {
public:
    string countOfAtoms(string formula) {
        int idx = 0;
        auto count = parse(formula, idx);
        ostringstream oss;
        for (auto &e : count) {
            oss << e.first;
            if (e.second > 1) oss << e.second;
        }
        return oss.str();
    }
    
    // 解析一层括号
    map<string, int> parse(const string &formula, int &idx) {
        const int N = formula.size();
        map<string, int> count;
        while (idx < N && formula[idx] != ')') {
            if (formula[idx] == '(') {
                idx++; // (
                auto paren = parse(formula, idx);
                idx++; // )
                int num = parseNum(formula, idx);
                for (auto &e : paren) { 
                    count[e.first] += e.second * num;                    
                }
            } else {
                auto name = parseName(formula, idx);
                int num = parseNum(formula, idx);
                count[name] += num;
            }
        }    
        return count;
    }
    
    int parseNum(const string &formula, int &idx) {
        int start = idx;
        while (idx < formula.size() && isdigit(formula[idx])) idx++;
        if (idx == start) return 1;
        return stoi(formula.substr(start, idx - start));
    }
    
    string parseName(const string &formula, int &idx) {
        int start = idx;
        idx++; // upper case
        while (idx < formula.size() && islower(formula[idx])) idx++;
        return formula.substr(start, idx - start);
    }
};

/*
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<map<string, int>> stk;
        stk.push({});
        
        const int N = formula.size();
        int idx = 0;
        while (idx < N) {
            if (formula[idx] == '(') {
                idx++; // (
                stk.push({});
            } else if (formula[idx] == ')') {
                idx++; // )
                auto top = stk.top(); stk.pop();
                int num = parseNum(formula, idx);
                for (auto &e : top) {
                    stk.top()[e.first] += e.second * num;
                }
            } else {
                auto name = parseName(formula, idx);
                int num = parseNum(formula, idx);
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
    
    int parseNum(const string &formula, int &idx) {
        int start = idx;
        while (idx < formula.size() && isdigit(formula[idx])) idx++;
        if (idx == start) return 1;
        return stoi(formula.substr(start, idx - start));
    }

    string parseName(const string &formula, int &idx) {
        int start = idx;
        idx++; // upper case
        while (idx < formula.size() && islower(formula[idx])) idx++;
        return formula.substr(start, idx - start);
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
