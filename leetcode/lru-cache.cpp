//
//  lru-cache
//  https://leetcode.com/problems/lru-cache/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache {
    // 把 entry{key,value} 用链表串起来，
    // 每次访问把entry移到表头，删除lru时删除表尾
    struct Entry {
        int key;
        int value;
    };
    list<Entry> l;                                 // 实际存储
    unordered_map<int, list<Entry>::iterator> mp;  // key=>entry
    int capacity;

private:
    void touch(int key) {
        // toList.splice(toListIterator, fromList, fromListSingleIterator)
        l.splice(l.begin(), l, mp[key]);
        mp[key] = l.begin();
    }

public:
    LRUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        touch(key);
        return mp[key]->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (!mp.count(key)) {            // 新增
            if (l.size() == capacity) {  // 删除表尾
                mp.erase(l.back().key);
                l.pop_back();
            }
            l.push_front({key, value});
            mp[key] = l.begin();
        } else {  // 更新
            mp[key]->value = value;
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

int main(int argc, const char* argv[]) {
    LRUCache cache(2);
    cout << cache.get(5) << endl;
    cache.set(5, 5);
    cout << cache.get(5) << endl;

    return 0;
}
