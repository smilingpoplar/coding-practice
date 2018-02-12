//
//  insert-delete-getrandom-o1-duplicates-allowed
//  https://leetcode.com/problems/insert-delete-getrandom-o1-duplicates-allowed/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class RandomizedCollection {
    vector<int> nums;
    unordered_map<int, unordered_set<int>> mp; // num => pos_set
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool ans = mp.find(val) == mp.end();
        mp[val].insert(nums.size());
        nums.push_back(val);
        return ans;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        if (mp.find(val) == mp.end()) return false;
        // 找到val的一个位置pos，若pos是nums的最后元素就直接删除，否则用nums的最后元素替换它
        int pos = *mp[val].begin();
        mp[val].erase(pos);
        if (mp[val].empty()) mp.erase(val);

        int lastIdx = nums.size() - 1;
        if (pos != lastIdx) {
            int lastVal = nums.back();
            mp[lastVal].erase(lastIdx);
            nums[pos] = lastVal;
            mp[lastVal].insert(pos);
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
