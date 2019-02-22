//
//  minimum-number-of-k-consecutive-bit-flips
//  https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // 从左往右遇到A[i]==0时将[i..i+K-1]翻转
        // 用flips记录[i..i+K-1]间累积的各次翻转，各次翻转用右端点表示
        const int N = A.size();
        deque<int> flips;
        int ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == flips.size() % 2) { // 这俩同0或同1，要翻转
                if (i + K - 1 >= N) return -1;
                flips.push_back(i + K - 1);
                ans++;
            }
            if (!flips.empty() && flips[0] == i) flips.pop_front();
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // 从左往右遇到A[i]==0时将[i..i+K-1]翻转
        // A[i]设为负值表示在[i..i+K-1]累积一次翻转
        const int N = A.size();
        int flips = 0, ans = 0; // flips表示A[i]处有多少翻转
        for (int i = 0; i < N; i++) {
            if (A[i] == flips % 2) { // 这俩同0或同1，要翻转
                if (i + K - 1 >= N) return -1;
                A[i] -= 2; // A[i]设为负值
                flips++, ans++;
            }
            // 最左影响到A[i]的端点是i-K+1
            int left = i - K + 1;
            if (left >= 0 && A[left] < 0) { // 为i++更新变量
                A[left] += 2;
                flips--;
            }
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
