//
//  lfu-cache
//  https://leetcode.com/problems/lfu-cache/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <list>
#include <map>

using namespace std;

class LFUCache {
    struct Entry {
        int freq;
        int key;
        int value;
    };
    map<int, list<Entry>> freqMp;                  // 实际存储，frep => list<Entry>
    unordered_map<int, list<Entry>::iterator> mp;  // key => 实际存储位置
    int capacity;

private:
    void incFreq(int key) {
        int freq = mp[key]->freq, value = mp[key]->value;
        // 从原频率行删除
        freqMp[freq].erase(mp[key]);
        if (freqMp[freq].empty()) {
            freqMp.erase(freq);
        }

        freq++;
        // 插入到新频率行
        freqMp[freq].push_front({freq, key, value});
        mp[key] = freqMp[freq].begin();
    }

    // 删除最小频率的行中最少最近使用项
    void evict() {
        if (freqMp.empty()) return;
        auto &l = freqMp.begin()->second;  // 最小频率行
        auto lfu = l.back();               // 最少最近使用的项
        l.pop_back();                      // 删除
        if (l.empty()) {
            freqMp.erase(lfu.freq);
        }
        mp.erase(lfu.key);
    }

public:
    LFUCache(int capacity) {
        this->capacity = capacity;
    }

    int get(int key) {
        if (!mp.count(key)) return -1;
        incFreq(key);
        return mp[key]->value;
    }

    void put(int key, int value) {
        if (capacity == 0) return;
        if (!mp.count(key)) {  // 新增
            if (mp.size() == capacity) evict();
            freqMp[1].push_front({1, key, value});
            mp[key] = freqMp[1].begin();
        } else {  // 更新
            mp[key]->value = value;
            incFreq(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */

int main(int argc, const char *argv[]) {
    LFUCache lfu(3);
    lfu.put(1, 1);
    lfu.put(2, 2);
    lfu.put(3, 3);
    lfu.put(4, 4);
    cout << lfu.get(4) << endl;  // 4
    cout << lfu.get(3) << endl;  // 3
    cout << lfu.get(2) << endl;  // 2
    cout << lfu.get(1) << endl;  // -1

    lfu.put(5, 5);
    cout << lfu.get(1) << endl;  // -1
    cout << lfu.get(2) << endl;  // 2
    cout << lfu.get(3) << endl;  // 3
    cout << lfu.get(4) << endl;  // -1
    cout << lfu.get(5) << endl;  // 5

    return 0;
}
