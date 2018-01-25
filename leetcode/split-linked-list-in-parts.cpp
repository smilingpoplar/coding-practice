//
//  split-linked-list-in-parts
//  https://leetcode.com/problems/split-linked-list-in-parts/
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
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int n = 0;
        for (auto p = root; p; p = p->next) {
            ++n;
        }
        
        vector<ListNode *> ans;
        int base = n / k;
        int remain = n % k;
        for (int i = 0; i < k; i++) {
            int length = base + (i < remain ? 1 : 0);
            // 从链表中取length长的子链表放入ans中
            ans.push_back(root);
            for (int j = 0; root && j < length - 1; j++) {
                root = root->next;
            }
            if (root) {
                auto next = root->next;
                root->next = nullptr;
                root = next;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
