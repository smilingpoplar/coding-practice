//
//  nim-game
//  https://leetcode.com/problems/nim-game/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool canWinNim(int n) {
        return n % 4 != 0;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
