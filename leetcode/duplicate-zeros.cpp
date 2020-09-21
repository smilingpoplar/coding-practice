//
//  duplicate-zeros
//  https://leetcode.com/problems/duplicate-zeros/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    void duplicateZeros(vector<int>& arr) {
        int zeroCnt = 0;
        for (int a : arr) {
            if (a == 0) zeroCnt++;
        }
        
        // 虚拟扩展位置到j=N-1+zeroCnt
        const int N = arr.size();
        for (int i = N - 1, j = N - 1 + zeroCnt; i >= 0; i--, j--) {
            if (arr[i]) {
                if (j < N) arr[j] = arr[i];
            } else {
                if (j < N) arr[j] = 0;
                j--;
                if (j < N) arr[j] = 0;
            }
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
