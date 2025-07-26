//
//  find-kth-to-tail
//  BM8 链表中倒数最后k个结点
//

#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        if (k == 0 || !pHead) return nullptr;
        auto fast = pHead;
        for (int i = 0; i < k; i++) {
            if (!fast) return nullptr;
            fast = fast->next;
        }

        auto slow = pHead;
        while (fast) {
            fast = fast->next;
            slow = slow->next;
        }
        return slow;
    }
};
