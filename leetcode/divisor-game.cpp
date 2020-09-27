//
//  divisor-game
//  https://leetcode.com/problems/divisor-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool divisorGame(int N) {
        // 如果N是奇数，只能选奇数x，N=N-x变成偶数
        // 如果N是偶数，总能选x=1，N=N-x变成奇数
        // N==1是递推基础，奇数，输
        return N % 2 == 0;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
