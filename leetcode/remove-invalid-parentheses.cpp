//
//  remove-invalid-parentheses
//  https://leetcode.com/problems/remove-invalid-parentheses/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        // 有多少左右括号不匹配待删除，
        // rmL和rmR将作为dfs的剪枝条件
        int rmL = 0, rmR = 0;
        for (char c : s) {
            if (c == '(') {
                rmL++;
            } else if (c == ')') {
                if (rmL > 0) rmL--; // 匹配
                else rmR++;
            }
        }

        vector<string> ans;
        remove(s, 0, 0, rmL, rmR, ans);
        return ans;
    }

    // s[..idx)的左括号比右括号多moreL，s[idx..]有rmL个'('待删除、rmR个')'待删除
    void remove(const string &s, int idx, int moreL, int rmL, int rmR, vector<string> &ans) {
        if (moreL < 0 || rmL < 0 || rmR < 0) return;
        const int N = s.size();

        for (int i = idx; i < N && moreL >= 0; i++) {
            if (s[i] == '(') {
                if (rmL > 0 && (i == idx || s[i] != s[i-1])) { // 连续'('只删第一个
                    remove(s.substr(0, i) + s.substr(i + 1), i, moreL, rmL - 1, rmR, ans);
                }
                moreL++;
            } else if (s[i] == ')') {
                if (rmR > 0 && (i == idx || s[i] != s[i-1])) {
                    remove(s.substr(0, i) + s.substr(i + 1), i, moreL, rmL, rmR - 1, ans);
                }
                moreL--;
            }
        }

        if (moreL == 0 && rmL == 0 && rmR == 0) {
            ans.push_back(s);
        }
    }
};

/*
class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> ans;
        search(s, 0, 0, "()", ans);
        return ans;
    }
    
    void search(const string &s, int idx, int lastRmIdx, const string &paren, vector<string> &ans) { 
        // 先从左往右扫，确保多出的左括号数leftDiff>=0；
        //  再从右往左扫，确保多出的右括号数>=0（等价于 将原串取反、改查右括号再来一遍）。
        // 从左往右遇到leftDiff<0时前缀串不合法，要从[lastRmIdx..i]间删除一个')'，连续')'只删第一个。
        //  将删除限制在[lastRmIdx..i]（而不是[0..i]），是为了防止因删除顺序不同导致剩下括号串重复；
        //  连续')'只删第一个，也是为了防止剩下括号串重复。
        int leftDiff = 0;
        for (int i = idx; i < s.size(); i++) {
            if (s[i] == paren[0]) leftDiff++;
            else if (s[i] == paren[1]) leftDiff--;
            if (leftDiff >= 0) continue;
            // 现在leftDiff<0，串无效
            for (int j = lastRmIdx; j <= i; j++) { // [lastRmIdx..i]间删除一个')'
                if (s[j] == paren[1] && (j == lastRmIdx || s[j] != s[j-1])) { // 连续')'只删第一个
                    // 删除第j后，原i+1因删除前移，递归从i开始
                    search(s.substr(0, j) + s.substr(j + 1), i, j, paren, ans);
                }
            }
            return; // 若不删除')'，串已无效，后面不用再看
        }

        string reversed(s.rbegin(), s.rend());
        if (paren[0] == '(') search(reversed, 0, 0, ")(", ans); // 进入第二遍处理，从右往左
        else ans.push_back(reversed); // 第二遍处理完
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
