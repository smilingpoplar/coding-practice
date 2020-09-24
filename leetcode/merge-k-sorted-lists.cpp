//
//  merge-k-sorted-lists
//  https://leetcode.com/problems/merge-k-sorted-lists/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        // 用最小堆k路归并
        auto cmp = [](ListNode *l1, ListNode *l2) {
            return l1->val > l2->val;
        };
        priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> Q(cmp);
        for (auto list : lists) {
            if (list) Q.push(list);
        }

        ListNode dummy(-1);
        auto p = &dummy;
        while (!Q.empty()) {
            auto node = Q.top(); Q.pop();
            p->next = node;
            p = node;
            if (node->next) Q.push(node->next);
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {
    ListNode l1(1);
    ListNode l2(2);
    ListNode l3(3);
    ListNode l4(4);
    ListNode l5(5);
    ListNode l6(6);
    l1.next = &l3;
    l3.next = &l5;
    l2.next = &l6;
    vector<ListNode *> lists = {&l1, &l2, &l4};
    
    Solution solution;
    auto head = solution.mergeKLists(lists);
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    
    return 0;
}
