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
    struct Bucket { int freq; list<int> keys; };
    list<Bucket> _buckets; // 按频率分桶
    typedef list<Bucket>::iterator BucketPtr;
    typedef list<int>::iterator KeyPtr;
    struct Info { BucketPtr bp; KeyPtr kp; int value; };
    unordered_map<int, Info> _infoOfKey; // key=>(桶指针，键指针，value)
    int _capacity;
public:
    LFUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (!_infoOfKey.count(key)) return -1;
        increaseFreq(key);
        return _infoOfKey[key].value;
    }
    
    // 将key从原行删除、插入"频率+1"行
    void increaseFreq(int key) {
        auto info = _infoOfKey[key];
        auto bucket = info.bp, nextBucket = next(bucket);
        int nextFreq = bucket->freq + 1;
        if (nextBucket == _buckets.end() || nextBucket->freq != nextFreq) { // 插入新行
            nextBucket = _buckets.insert(nextBucket, { nextFreq, { }});
        }
        bucket->keys.erase(info.kp);
        if (bucket->keys.empty()) _buckets.erase(bucket);

        nextBucket->keys.push_front(key);
        _infoOfKey[key] = { nextBucket, nextBucket->keys.begin(), info.value };
    }
    
    void put(int key, int value) {
        if (_capacity == 0) return;
        if (!_infoOfKey.count(key)) {
            if (_infoOfKey.size() == _capacity) evict();
            // 应插入频率为1的行。这里先设频率为0，然后和后面情况一起处理。
            auto bucket = _buckets.insert(_buckets.begin(), { 0, { key } });
            _infoOfKey[key] = { bucket, bucket->keys.begin(), value };
        } else {
            _infoOfKey[key].value = value;
        }
        increaseFreq(key);
    }
    
    // 删除最小频率lfu的桶中最少最近使用lru的key
    void evict() {
        if (_buckets.empty()) return;
        auto &keysInBucket = _buckets.begin()->keys;
        _infoOfKey.erase(keysInBucket.back());
        keysInBucket.pop_back();
        if (keysInBucket.empty()) _buckets.erase(_buckets.begin());
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
