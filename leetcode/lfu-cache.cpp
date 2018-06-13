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
    struct KV { int key; int value; };
    struct Bucket { int freq; list<KV> kvs; };
    list<Bucket> buckets; // 按频率分桶
    struct Info { list<Bucket>::iterator bp; list<KV>::iterator kvp; };
    unordered_map<int, Info> infoOfKey;
    int capacity;
public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    
    int get(int key) {
        if (!infoOfKey.count(key)) return -1;
        increaseFreq(key);
        return infoOfKey[key].kvp->value;
    }
    
    // 将kv从原行删除、插入"频率+1"行
    void increaseFreq(int key) {
        auto info = infoOfKey[key];
        auto bucket = info.bp, nextBucket = next(bucket);
        int nextFreqNeeded = bucket->freq + 1;
        if (nextBucket == buckets.end() || nextBucket->freq != nextFreqNeeded) { // 插入新行
            nextBucket = buckets.insert(nextBucket, { nextFreqNeeded, { }});
        }
        nextBucket->kvs.splice(nextBucket->kvs.begin(), bucket->kvs, info.kvp);
        if (bucket->kvs.empty()) buckets.erase(bucket);
        infoOfKey[key] = { nextBucket, nextBucket->kvs.begin() };
    }
    
    void put(int key, int value) {
        if (capacity == 0) return;
        if (!infoOfKey.count(key)) {
            if (infoOfKey.size() == capacity) evict();
            // 应插入频率为1的行。这里先设频率为0，然后和后面情况一起处理。
            auto bucket = buckets.insert(buckets.begin(), { 0, {{key, value}} });
            infoOfKey[key] = { bucket, bucket->kvs.begin() };
        } else {
            infoOfKey[key].kvp->value = value;
        }
        increaseFreq(key);
    }
    
    // 删除最小频率lfu的桶中最少最近使用lru项
    void evict() {
        if (buckets.empty()) return;
        auto lfu = buckets.begin();
        infoOfKey.erase(lfu->kvs.back().key);
        lfu->kvs.pop_back();
        if (lfu->kvs.empty()) buckets.erase(lfu);
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
