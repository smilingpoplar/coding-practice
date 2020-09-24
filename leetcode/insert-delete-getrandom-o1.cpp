//
//  insert-delete-getrandom-o1
//  https://leetcode.com/problems/insert-delete-getrandom-o1/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class RandomizedSet {
    vector<int> nums;
    unordered_map<int, int> mp; // num => idx
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        srand(time(NULL));
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (mp.count(val)) return false;
        mp[val] = nums.size();
        nums.push_back(val);
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (!mp.count(val)) return false;
        // 找到val的位置idx，
        // 若idx是nums的最后元素就直接删除，否则用nums的最后元素替换它
        int idx = mp[val];
        mp.erase(val);

        int lastIdx = nums.size() - 1;
        if (idx != lastIdx) {
            int lastVal = nums.back();
            mp.erase(lastVal);
            mp[lastVal] = idx;
            nums[idx] = lastVal;
        }
        nums.pop_back();
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */

int main(int argc, const char * argv[]) {
    return 0;
}
