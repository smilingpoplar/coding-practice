//
//  sort-transformed-array
//  https://leetcode.com/problems/sort-transformed-array/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
        // 类似归并法，两端指针
        // a>0时取两端大中间小，取大的那个放数组后面；a<0是两端小中间大，取小的那个放数组前面；a==0时可并到前面任一种中处理
        const int N = nums.size();
        vector<int> ans(N);
        int i = 0, j = N - 1;
        if (a > 0) {
            int k = N - 1;
            while (i <= j) {
                int quadI = quad(nums[i], a, b, c), quadJ = quad(nums[j], a, b, c);
                if (quadI > quadJ) { ans[k--] = quadI; i++; } 
                else { ans[k--] = quadJ; j--; }
            }            
        } else {
            int k = 0;
            while (i <= j) {
                int quadI = quad(nums[i], a, b, c), quadJ = quad(nums[j], a, b, c);
                if (quadI < quadJ) { ans[k++] = quadI; i++; }
                else { ans[k++] = quadJ; j--; }
            }
        }
        return ans;
    }
    
    int quad(int x, int a, int b, int c) {
        return a * x * x + b * x + c;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}