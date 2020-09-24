//
//  implement-rand10-using-rand7
//  https://leetcode.com/problems/implement-rand10-using-rand7/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

// The rand7() API is already defined for you.
// int rand7();
// @return a random integer in the range 1 to 7

class Solution {
public:
    int rand10() {
        // rejection sampling
        // 用两个rand7()调用生成[0-48]的平均分布，使用其中的[0-39]，
        // 利用率40/49，平均每个随机数调用rand7()：2/(40/49)=2.45次
        while (true) {
            int num = (rand7() - 1) * 7 + (rand7() - 1);
            if (num < 40) return num % 10 + 1;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
