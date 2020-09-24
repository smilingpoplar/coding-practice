//
//  find-the-winner-of-an-array-game
//  https://leetcode.com/problems/find-the-winner-of-an-array-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        const int N = arr.size();
        int winVal = arr[0], winCnt = 0;
        for (int i = 1; i < N; i++) {
            if (arr[i] > winVal) {
                winVal = arr[i];
                winCnt = 1;
            } else {
                winCnt++;
            }
            if (winCnt == k) return winVal;
        }
        return winVal;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
