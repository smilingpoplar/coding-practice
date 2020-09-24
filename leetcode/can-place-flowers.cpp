//
//  can-place-flowers
//  https://leetcode.com/problems/can-place-flowers/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        // 贪心法，能种就种
        const int N = flowerbed.size();
        int count = 0;
        for (int i = 0; i < N; i++) {
            if (!flowerbed[i] 
                && (i - 1 < 0 || !flowerbed[i-1]) 
                && (i + 1 >= N || !flowerbed[i+1])) {
                flowerbed[i] = 1;
                count++;
            }
            if (count >= n) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
