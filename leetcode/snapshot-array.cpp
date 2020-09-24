//
//  snapshot-array
//  https://leetcode.com/problems/snapshot-array/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class SnapshotArray {
    vector<map<int, int>> data; // 每个slot记录历史修改{snapId,val}
    int snapId = 0;
public:
    SnapshotArray(int length) : data(length) {
    }
    
    void set(int index, int val) {
        data[index][snapId] = val;
    }
    
    int snap() {
        snapId++;
        return snapId - 1;
    }
    
    int get(int index, int snap_id) {
        auto &mp = data[index];
        // 找<=snap_id时的值
        auto it = mp.upper_bound(snap_id);
        if (it == mp.begin()) return NULL;
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

int main(int argc, const char * argv[]) {    
    return 0;
}
