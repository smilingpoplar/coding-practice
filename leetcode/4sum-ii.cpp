//
//  4sum-ii
//  https://leetcode.com/problems/4sum-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
        map<int, int> count; // sum=>count
        for (int a : A) {
            for (int b : B) {
                count[a + b]++;
            }
        }
        int ans = 0;
        for (int c : C) {
            for (int d : D) {
                int sum = c + d;
                if (count.count(-sum)) {
                    ans += count[-sum];
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
