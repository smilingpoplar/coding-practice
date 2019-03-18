//
//  lfu-cache
//  https://leetcode.com/problems/lfu-cache/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class LFUCache {
    // 映射表table按频率分行，每行行首放最近使用项
    struct Entry { int key; int value; };
    struct FreqRow { int freq; list<Entry> entries; };
    list<FreqRow> table; 
    struct EntryPtr { list<FreqRow>::iterator row; list<Entry>::iterator entry; };
    unordered_map<int, EntryPtr> entryPtr;
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!entryPtr.count(key)) return -1;
        increaseFreq(key);
        return entryPtr[key].entry->value;
    }
    
    // 将entry从原行删除、插入"freq+1"行
    void increaseFreq(int key) {
        auto ptr = entryPtr[key];
        auto currRow = ptr.row, nextRow = next(currRow);
        int nextFreq = currRow->freq + 1;
        if (nextRow == table.end() || nextRow->freq != nextFreq) { // 插入新行
            nextRow = table.insert(nextRow, { nextFreq, { }});
        }
        nextRow->entries.splice(nextRow->entries.begin(), currRow->entries, ptr.entry);
        if (currRow->entries.empty()) table.erase(currRow);
        entryPtr[key] = { nextRow, nextRow->entries.begin() };
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!entryPtr.count(key)) {
            if (entryPtr.size() == capacity) evict();
            // 应插入freq=1的行。这里先设freq=0，待会儿和其他情况一起增1。
            auto row = table.insert(table.begin(), { 0, {{key, value}} });
            entryPtr[key] = { row, row->entries.begin() };
        } else {
            entryPtr[key].entry->value = value;
        }
        increaseFreq(key);
    }
    
    // 删除最小频率lfu的行中最少最近使用lru项
    void evict() {
        if (table.empty()) return;
        auto lfu = table.begin();
        entryPtr.erase(lfu->entries.back().key);
        lfu->entries.pop_back();
        if (lfu->entries.empty()) table.erase(lfu);
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
