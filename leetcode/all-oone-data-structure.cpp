//
//  all-oone-data-structure
//  https://leetcode.com/problems/all-oone-data-structure/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class AllOne {
    // 映射表table按值分行
    struct ValueRow { int value; unordered_set<string> keys; };
    list<ValueRow> table;
    unordered_map<string, list<ValueRow>::iterator> rowPtrs;
private:
    void deleteKey(const string &key, list<ValueRow>::iterator &row) {
        row->keys.erase(key);
        if (row->keys.empty()) table.erase(row);
        rowPtrs.erase(key);
    }

    void insertKey(const string &key, list<ValueRow>::iterator &row) {
        row->keys.insert(key);
        rowPtrs[key] = row;
    }

    void moveKey(const string &key, list<ValueRow>::iterator &from, list<ValueRow>::iterator &to) {
        deleteKey(key, from);
        insertKey(key, to);
    }
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!rowPtrs.count(key)) { // 先插入0，待会儿和其他情况一起增1
            rowPtrs[key] = table.insert(table.begin(), {0, { key }}); 
        }
        auto currRow = rowPtrs[key], nextRow = next(currRow); 
        int nextValueNeeded = currRow->value + 1;
        if (nextRow == table.end() || nextRow->value != nextValueNeeded) { // 插入新行
            nextRow = table.insert(nextRow, {nextValueNeeded, { }});
        }
        moveKey(key, currRow, nextRow);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!rowPtrs.count(key)) return;
        auto currRow = rowPtrs[key];
        if (currRow->value == 1) {
            deleteKey(key, currRow);
            return;
        }
        auto prevRow = prev(currRow);
        int prevValueNeeded = currRow->value - 1;
        if (currRow == table.begin() || prevRow->value != prevValueNeeded) {
            prevRow = table.insert(currRow, {prevValueNeeded, { }});
        }
        moveKey(key, currRow, prevRow);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return table.empty() ? "" : *table.rbegin()->keys.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return table.empty() ? "" : *table.begin()->keys.begin();        
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne obj = new AllOne();
 * obj.inc(key);
 * obj.dec(key);
 * string param_3 = obj.getMaxKey();
 * string param_4 = obj.getMinKey();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
