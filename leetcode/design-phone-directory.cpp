//
//  design-phone-directory
//  https://leetcode.com/problems/design-phone-directory/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class PhoneDirectory {
    vector<int> nums;  // 存放数字
    int numCnt;
    vector<bool> used; // 数字是否使用
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) : nums(maxNumbers), used(maxNumbers, false) {
        for (int i = 0; i < maxNumbers; i++)
            nums[i] = i;
        numCnt = maxNumbers;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (numCnt <= 0) return -1;
        int num = nums[--numCnt];
        used[num] = true;
        return num;
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return !used[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        if (!used[number]) return;
        used[number] = false;
        nums[numCnt++] = number;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */

int main(int argc, const char * argv[]) {
    return 0;
}
