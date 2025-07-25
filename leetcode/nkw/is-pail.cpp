//
//  is-pail
//  BM13 判断一个链表是否为回文结构
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
    bool isPail(ListNode* head) {
        if (!head || !head->next) return true;
        auto fast = head->next, slow = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            slow = slow->next;
        }
        auto head2 = slow->next;
        slow->next = nullptr;
        head2 = reverse(head2);

        while (head && head2) {
            if (head->val != head2->val) {
                return false;
            }
            head = head->next;
            head2 = head2->next;
        }
        return true;
    }

    ListNode* reverse(ListNode* head) {
        ListNode* list = nullptr;
        while (head) {
            auto next = head->next;
            head->next = list;
            list = head;
            head = next;
        }
        return list;
    }
};