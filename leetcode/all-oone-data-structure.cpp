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

// https://leetcode.com/problems/all-oone-data-structure/discuss/91398/C++-solution-with-comments

class AllOne {
    struct Bucket { 
        const int value; 
        unordered_set<string> keys;
    };
    list<Bucket> buckets; // 按值分桶
    unordered_map<string, list<Bucket>::iterator> bucketOfKey;
public:
    /** Initialize your data structure here. */
    AllOne() {
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (!bucketOfKey.count(key)) {
            // 先插入0，待会儿和其他情况一起增1
            bucketOfKey[key] = buckets.insert(buckets.begin(), {0, { key }}); 
        }
        // 增1即将key移入下一桶
        auto bucket = bucketOfKey[key], nextBucket = next(bucket); 
        int nextValueNeeded = bucket->value + 1;
        if (nextBucket == buckets.end() || nextBucket->value != nextValueNeeded) {
            nextBucket = buckets.insert(nextBucket, {nextValueNeeded, { }});
        }
        nextBucket->keys.insert(key);
        bucketOfKey[key] = nextBucket;
        // 从桶中删除key
        bucket->keys.erase(key);
        if (bucket->keys.empty()) buckets.erase(bucket);
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (!bucketOfKey.count(key)) return;
        // 减1即将key移入上一桶
        auto bucket = bucketOfKey[key], prevBucket = prev(bucket);
        if (bucket->value > 1) {
            int prevValueNeeded = bucket->value - 1;
            if (bucket == buckets.begin() || prevBucket->value != prevValueNeeded) {
                prevBucket = buckets.insert(bucket, {prevValueNeeded, { }});
            } 
            prevBucket->keys.insert(key);
            bucketOfKey[key] = prevBucket;
        } else {
            bucketOfKey.erase(key);
        }
        // 从旧桶删除key
        bucket->keys.erase(key);
        if (bucket->keys.empty()) buckets.erase(bucket);
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return buckets.empty() ? "" : *buckets.rbegin()->keys.begin();
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return buckets.empty() ? "" : *buckets.begin()->keys.begin();        
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
