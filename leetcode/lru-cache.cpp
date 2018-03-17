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
    // 1. 按key分桶，每桶只要存key和value
    // 2. 用双向链表存储桶，每次访问把桶移到链表头，删除lru时只要删除链表尾
    // 3. 用哈希表映射 key=>指向桶的iterator
    struct Bucket { int key; int value; };
    list<Bucket> _buckets;
    unordered_map<int, list<Bucket>::iterator> _bucketOfKey;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (!_bucketOfKey.count(key)) return -1;
        touch(key);
        return _bucketOfKey[key]->value;
    }
    
    // 把桶移到链表头，更新哈希表中的映射
    void touch(int key) {
        _buckets.splice(_buckets.begin(), _buckets, _bucketOfKey[key]);
        _bucketOfKey[key] = _buckets.begin();
    }
    
    void put(int key, int value) {
        if (_capacity == 0) return;
        if (!_bucketOfKey.count(key)) {
            if (_buckets.size() == _capacity) { // 删除链表尾
                _bucketOfKey.erase(_buckets.back().key);
                _buckets.pop_back();
            }
            _buckets.push_front({key, value});
            _bucketOfKey[key] = _buckets.begin();
        } else {
            _bucketOfKey[key]->value = value;
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
