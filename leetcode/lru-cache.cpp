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
    // 1. 用双向链表std::list存储节点，这样移动节点时效率高（单向链表删除节点时查找前驱节点的效率低）
    // 2. 用哈希表std::unordered_map存储key=>链表节点地址的映射，这样查找节点O(1)时间
    // 3. 每次把访问的节点移动到链表头，这样当空间不够删除LRU节点时只要删除链表尾节点
private:
    struct CacheNode {
        CacheNode(int k, int v) : key(k), value(v) { }
        int key;
        int value;
    };

public:
    LRUCache(int capacity) {
        _capacity = capacity;
    }
    
    int get(int key) {
        if (_map.find(key) == _map.end()) return -1;
        // 把访问的节点移动到链表头，并更新map中该节点的地址
        _list.splice(_list.begin(), _list, _map[key]);
        _map[key] = _list.begin();
        return _map[key]->value;
    }
    
    void set(int key, int value) {
        if (_map.find(key) != _map.end()) {
            // 更新节点的值，并把节点移动到链表头，更新map中该节点的地址
            _map[key]->value = value;
            _list.splice(_list.begin(), _list, _map[key]);
            _map[key] = _list.begin();
        } else { // 添加节点
            if (_list.size() == _capacity) { // 删除链表尾
                _map.erase(_list.back().key);
                _list.pop_back();
            }
            // 在链表头添加节点，更新map中该节点的地址
            _list.push_front(CacheNode(key, value));
            _map[key] = _list.begin();
        }
    }
private:
    list<CacheNode> _list;
    unordered_map<int, list<CacheNode>::iterator> _map;
    int _capacity;
};

int main(int argc, const char * argv[]) {
    LRUCache cache(2);
    cout << cache.get(5) << endl;
    cache.set(5, 5);
    cout << cache.get(5) << endl;
    
    return 0;
}
