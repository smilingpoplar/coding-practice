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
        // 使用map
        unordered_map<RandomListNode *, RandomListNode *> copied;
        auto current = head;
        while (current) {
            if (!copied[current]) copied[current] = new RandomListNode(current->label);

            auto next = current->next;
            if (next && !copied[next]) copied[next] = new RandomListNode(next->label);
            copied[current]->next = copied[next];

            auto random = current->random;
            if (random && !copied[random]) copied[random] =  new RandomListNode(random->label);
            copied[current]->random = copied[random];

            current = current->next;
        }
        return copied[head];
    }
};
*/

class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        // 在每个结点后放copy结点
        auto current = head;
        while (current) {
            auto next = current->next;
            auto copy = new RandomListNode(current->label);
            copy->next = next;
            current->next = copy;
            current = next;
        }
        // 设置copy结点的random指针
        current = head;
        while (current) {
            auto copy = current->next;
            if (current->random) copy->random = current->random->next;
            current = copy->next;
        }
        // 拆分两个链表
        RandomListNode dummy(-1);
        RandomListNode *currentDummy = &dummy;
        current = head;
        while (current) {
            auto copy = current->next;
            auto next = copy->next;
            currentDummy->next = copy;
            currentDummy = copy;
            current->next = next;
            current = next;
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