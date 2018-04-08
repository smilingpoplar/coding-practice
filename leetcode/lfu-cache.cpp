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
    list<Bucket> buckets; // 按频率分桶
    typedef list<Bucket>::iterator BucketPtr;
    typedef list<int>::iterator KeyPtr;
    struct Info { BucketPtr bp; KeyPtr kp; int value; };
    unordered_map<int, Info> infoOfKey; // key=>(桶指针，键指针，value)
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!infoOfKey.count(key)) return -1;
        increaseFreq(key);
        return infoOfKey[key].value;
    }
    
    // 将key从原行删除、插入"频率+1"行
    void increaseFreq(int key) {
        auto info = infoOfKey[key];
        auto bucket = info.bp, nextBucket = next(bucket);
        int nextFreq = bucket->freq + 1;
        if (nextBucket == buckets.end() || nextBucket->freq != nextFreq) { // 插入新行
            nextBucket = buckets.insert(nextBucket, { nextFreq, { }});
        }
        bucket->keys.erase(info.kp);
        if (bucket->keys.empty()) buckets.erase(bucket);

        nextBucket->keys.push_front(key);
        infoOfKey[key] = { nextBucket, nextBucket->keys.begin(), info.value };
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!infoOfKey.count(key)) {
            if (infoOfKey.size() == capacity) evict();
            // 应插入频率为1的行。这里先设频率为0，然后和后面情况一起处理。
            auto bucket = buckets.insert(buckets.begin(), { 0, { key } });
            infoOfKey[key] = { bucket, bucket->keys.begin(), value };
        } else {
            infoOfKey[key].value = value;
        }
        increaseFreq(key);
    }
    
    // 删除最小频率lfu的桶中最少最近使用lru的key
    void evict() {
        if (buckets.empty()) return;
        auto &keysInBucket = buckets.begin()->keys;
        infoOfKey.erase(keysInBucket.back());
        keysInBucket.pop_back();
        if (keysInBucket.empty()) buckets.erase(buckets.begin());
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
