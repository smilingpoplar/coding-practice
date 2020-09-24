//
//  two-sum-iii-data-structure-design
//  https://leetcode.com/problems/two-sum-iii-data-structure-design/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class TwoSum {
    unordered_map<int, int> cnt; // num=>count
public:
    /** Initialize your data structure here. */
    TwoSum() {
    }
    
    /** Add the number to an internal data structure.. */
    void add(int number) {
        cnt[number]++;
    }
    
    /** Find if there exists any pair of numbers which sum is equal to the value. */
    bool find(int value) {
        // 遍历map，对每个数num看value-num是否存在
        for (auto &e : cnt) {
            int num = e.first, cnt = e.second;
            int toFind = value - num;
            if ((toFind == num && cnt[toFind] > 1) || (toFind != num && cnt.count(toFind))) 
                return true;
        }
        return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum obj = new TwoSum();
 * obj.add(number);
 * bool param_2 = obj.find(value);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
