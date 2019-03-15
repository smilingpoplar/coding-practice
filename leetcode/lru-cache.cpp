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
    // 1. table只有单列，按key分行 => entry{key,value}
    // 2. 每次访问把entry移到列头，删除lru时只要删除列尾
    struct Entry { int key; int value; };
    list<Entry> table;
    unordered_map<int, list<Entry>::iterator> entryPtr;
    int capacity;
public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!entryPtr.count(key)) return -1;
        touch(key);
        return entryPtr[key]->value;
    }
    
    void touch(int key) {
        // toList.splice(toListIterator, fromList, fromListSingleIterator)
        table.splice(table.begin(), table, entryPtr[key]);
        entryPtr[key] = table.begin();
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!entryPtr.count(key)) {
            if (table.size() == capacity) { // 删除列尾
                entryPtr.erase(table.back().key);
                table.pop_back();
            }
            table.push_front({key, value});
            entryPtr[key] = table.begin();
        } else {
            entryPtr[key]->value = value;
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
