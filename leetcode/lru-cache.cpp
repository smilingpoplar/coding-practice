//
//  sort-list
//  https://leetcode.com/problems/sort-list/
//
//  Created by smilingpoplar on 15/6/5.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

class LRUCache{
    // 1. 按key分桶，每桶只要存KVPair
    // 2. 用双向链表std::list存储桶，每次访问把桶移到链表头，这样当空间不够时只要删除尾节点
    // 3. 用哈希表std::unordered_map映射key=>链表节点的iterator，这样O(1)时间查找
    struct KVPair { int key; int value; };
    list<KVPair> _list;
    unordered_map<int, list<KVPair>::iterator> _map;
    int _capacity;
public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        touch(key);
        return _map[key]->value;
    }
    
    void put(int key, int value) {
        if (_map.find(key) != _map.end()) {
            _map[key]->value = value;
            touch(key);
        } else { // 添加节点
            _list.push_front({key, value});
            _map[key] = _list.begin();
            if (_list.size() > _capacity) { // 删除链表尾
                _map.erase(_list.back().key);
                _list.pop_back();
            }
        }
    }
private:
    void touch(int key) {
        // 把节点移动到链表头，更新map中该键的映射
        _list.splice(_list.begin(), _list, _map[key]);
        _map[key] = _list.begin();        
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
