//
//  remove-zero-sum-consecutive-nodes-from-linked-list
//  https://leetcode.com/problems/remove-zero-sum-consecutive-nodes-from-linked-list/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode dummy;
        dummy.next = head;
        unordered_map<int, ListNode*> mp; // presum=>node
        int presum = 0;
        auto cur = &dummy;
        while (cur) {
            presum += cur->val;
            if (mp.count(presum)) { // 删除[mp[presum]->next..cur]间的节点
                auto p = mp[presum]->next;
                int tmpsum = presum + p->val;
                while (tmpsum != presum) {
                    mp.erase(tmpsum);
                    p = p->next;
                    tmpsum += p->val;
                }
                mp[presum]->next = cur->next;
            } else {
                mp[presum] = cur;
            }
            cur = cur->next;
        }
        return dummy.next;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
