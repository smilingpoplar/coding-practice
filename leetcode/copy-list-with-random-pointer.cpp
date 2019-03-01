//
//  copy-list-with-random-pointer
//  https://leetcode.com/problems/copy-list-with-random-pointer/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

struct RandomListNode {
    int label;
    RandomListNode *next, *random;
    RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
};

/*
#include <unordered_map>

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 使用map记录
        unordered_map<RandomListNode *, RandomListNode *> copied;
        auto curr = head;
        while (curr) {
            if (!copied[curr]) copied[curr] = new RandomListNode(curr->label);

            auto next = curr->next;
            if (next && !copied[next]) copied[next] = new RandomListNode(next->label);
            copied[curr]->next = copied[next];

            auto random = curr->random;
            if (random && !copied[random]) copied[random] =  new RandomListNode(random->label);
            copied[curr]->random = copied[random];

            curr = curr->next;
        }
        return copied[head];
    }
};
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 在每个l1节点后放l2节点
        auto l1 = head;
        while (l1) {
            auto next = l1->next;
            auto l2 = new RandomListNode(l1->label);
            l2->next = next;
            l1->next = l2;
            l1 = next;
        }
        // 设置l2节点的random指针
        l1 = head;
        while (l1) {
            auto l2 = l1->next;
            if (l1->random) l2->random = l1->random->next;
            l1 = l2->next;
        }
        // 拆分两个链表
        RandomListNode dummy(-1);
        auto p = &dummy;
        l1 = head;
        while (l1) {
            auto l2 = l1->next;
            auto next = l2->next;
            p->next = l2;
            p = l2;
            l1->next = next;
            l1 = l1->next;
        }
        return dummy.next;
    }
};

void printAlongRandom(RandomListNode *head) {
    auto fast = head;
    auto slow = head;
    while (true) {
        if (!slow) break;
        cout << slow->label << " ";
        if (!fast || !fast->random) break;
        fast = fast->random->random;
        slow = slow->random;
        if (fast == slow) break;
    }
    cout << endl;
}

void print(RandomListNode *head) {
    while (head) {
        printAlongRandom(head);
        head = head->next;
    }
}

int main(int argc, const char * argv[]) {
    RandomListNode l1(1);
    RandomListNode l2(2);
    RandomListNode l3(3);
    RandomListNode l4(4);
    RandomListNode l5(5);
    l1.next = &l2;
    l2.next = &l3;
    l2.random = &l4;
    l3.next = &l4;
    l3.random = &l4;
    l4.next = &l5;
    l4.random = &l2;
    
    Solution solution;
    auto head = solution.copyRandomList(&l1);
    print(head);
    
    return 0;
}