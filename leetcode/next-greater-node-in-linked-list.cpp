//
//  next-greater-node-in-linked-list
//  https://leetcode.com/problems/next-greater-node-in-linked-list/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> arr;
        while (head) {
            arr.push_back(head->val);
            head = head->next;
        }

        const int N = arr.size();
        vector<int> ans(N, 0);
        stack<int> stk;  // 单调栈，保存下标
        for (int i = 0; i < N; i++) {
            while (!stk.empty() && arr[i] > arr[stk.top()]) {
                ans[stk.top()] = arr[i];
                stk.pop();
            }
            stk.push(i);
        }
        return ans;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
