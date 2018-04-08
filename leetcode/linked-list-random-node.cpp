//
//  linked-list-random-node
    //  https://leetcode.com/problems/linked-list-random-node/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
    class Solution {
        ListNode *head;
    public:
        /** @param head The linked list's head.
            Note that the head is guaranteed to be not null, so it contains at least one node. */
        Solution(ListNode* head) {
            this->head = head;
            srand(time(NULL));
        }
        
        /** Returns a random node's value. */
        int getRandom() {
            int ans = INT_MIN;
            int count = 0;
            for (auto curr = head; curr; curr = curr->next) {
                count++;
                if (rand() % count == 0) ans = curr->val;
            }
            return ans;
        }
    };

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(head);
 * int param_1 = obj.getRandom();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
