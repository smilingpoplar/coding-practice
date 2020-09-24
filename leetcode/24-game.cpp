//
//  24-game
//  https://leetcode.com/problems/24-game/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool judgePoint24(vector<int>& nums) {
        vector<double> v(nums.begin(), nums.end());
        return solve(v);
    }
    
    bool solve(vector<double>& nums) {
        const vector<char> ops = {'+', '-', '*', '/'};
        const int N = nums.size();
        const double EPSILON = 1e-6;
        if (N == 1) return abs(nums[0] - 24) < EPSILON;
        
        // 任取两个数
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (i == j) continue;        
                // 先把剩下的数放入新数组
                vector<double> arr;
                for (int k = 0; k < N; k++) {
                    if (k != i && k != j) {
                        arr.push_back(nums[k]);
                    }
                }
                
                for (char op : ops) {
                    if ((op == '+' || op == '*') && i > j) continue; // +*满足交换律，减少重复计算
                    if (op == '/' && abs(nums[j]) < EPSILON) continue;
                    
                    double ans;
                    if (op == '+') ans = nums[i] + nums[j];
                    else if (op == '-') ans = nums[i] - nums[j];
                    else if (op == '*') ans = nums[i] * nums[j];
                    else if (op == '/') ans = nums[i] / nums[j];
                    arr.push_back(ans);    
                    if (solve(arr)) return true;
                    arr.pop_back();
                }
            }
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
