//
//  lexicographical-numbers
//  https://leetcode.com/problems/lexicographical-numbers/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // 十叉树的先序遍历
        vector<int> ans;
        for (int i = 1; i <= 9; i++) {
            preorder(i, n, ans);
        }
        return ans;
    }
    
    void preorder(int x, int n, vector<int> &ans) {
        if (x > n) return;
        ans.push_back(x);
        for (int i = 0; i <= 9; i++) {
            preorder(x * 10 + i, n, ans);
        }
    }
};
*/

class Solution {
public:
    vector<int> lexicalOrder(int n) {
        // 十叉树的先序遍历
        vector<int> ans;
        stack<int> stk;
        for (int i = 9; i >= 1; i--) {
            if (i <= n) stk.push(i);
        }
        while (!stk.empty()) {
            int x = stk.top(); stk.pop();
            ans.push_back(x);
            for (int i = 9; i >= 0; i--) {
                int next = x * 10 + i;
                if (next <= n) stk.push(next);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
