//
//  convert-binary-number-in-a-linked-list-to-integer
//  https://leetcode.com/problems/convert-binary-number-in-a-linked-list-to-integer/
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
    int getDecimalValue(ListNode* head) {
        int ans = 0;
        while (head) {
            ans = ans * 2 + head->val;
            head = head->next;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
