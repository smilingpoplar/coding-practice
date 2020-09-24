//
//  detect-pattern-of-length-m-repeated-k-or-more-times
//  https://leetcode.com/problems/detect-pattern-of-length-m-repeated-k-or-more-times/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool containsPattern(vector<int>& arr, int m, int k) {
        // 是否有m长子段重复k次
        const int N = arr.size();
        int count = 0;
        for (int i = 0; i + m < N; i++) {
            if (arr[i] != arr[i+m]) {
                count = 0;
            } else {
                count++;
                if (count == m * (k-1)) return true;
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
