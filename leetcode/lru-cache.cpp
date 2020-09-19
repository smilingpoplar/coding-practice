//
//  lru-cache
//  https://leetcode.com/problems/lru-cache/
//
//  Created by smilingpoplar on 15/6/5.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
    // 把entry{key,value}用链表串起来，
    // 每次访问把entry移到表头，删除lru时删除表尾
    struct Entry { int key; int value; };
    list<Entry> l; // 实际存储
    unordered_map<int, list<Entry>::iterator> entryPtrs; // key=>entry
    int capacity;
private:
    void touch(int key) {
        // toList.splice(toListIterator, fromList, fromListSingleIterator)
        l.splice(l.begin(), l, entryPtrs[key]);
        entryPtrs[key] = l.begin();
    }
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!entryPtrs.count(key)) return -1;
        touch(key);
        return entryPtrs[key]->value;
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!entryPtrs.count(key)) {
            if (l.size() == capacity) { // 删除表尾
                entryPtrs.erase(l.back().key);
                l.pop_back();
            }
            l.push_front({key, value});
            entryPtrs[key] = l.begin();
        } else {
            entryPtrs[key]->value = value;
            touch(key);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache obj = new LRUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, const char * argv[]) {
    LRUCache cache(2);
    cout << cache.get(5) << endl;
    cache.set(5, 5);
    cout << cache.get(5) << endl;
    
    return 0;
}
