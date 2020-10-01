//
//  jump-game-iii
//  https://leetcode.com/problems/jump-game-iii/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canReach(vector<int>& arr, int st) {
        if (st < 0 || st >= arr.size() || arr[st] < 0) return false;
        if (arr[st] == 0) return true;
        arr[st] *= -1; // 标记为已访问
        int val = abs(arr[st]);
        return canReach(arr, st - val) || canReach(arr, st + val);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
