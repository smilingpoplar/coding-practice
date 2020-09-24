//
//  chalkboard-xor-game
//  https://leetcode.com/problems/chalkboard-xor-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        for (int num : nums) x ^= num;
        // 如果xor!=0，Alice要想赢只能指望Bob拿最后一个（即数有偶数个）
        return x == 0 || nums.size() % 2 == 0;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
