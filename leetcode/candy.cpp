//
//  candy
//  https://leetcode.com/problems/candy/
//
//  Created by smilingpoplar on 15/5/8.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // 比左侧分高的糖果比左侧多，比右侧分高的糖果比右侧多，分从左往右和从右往左两趟扫描分别算出糖果数，取较大值
        const int N = (int)ratings.size();
        vector<int> candies(N, 1);
        // 从左往右扫描
        for (int i = 1, num = 1; i < N; i++) {
            if (ratings[i] > ratings[i - 1]) {
                ++num;
            } else {
                num = 1;
            }
            if (num > candies[i]) candies[i] = num;
        }
        // 从右往左扫描
        for (int i = N - 2, num = 1; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                ++num;
            } else {
                num = 1;
            }
            if (num > candies[i]) candies[i] = num;
        }
        // 总和
        int sum = 0;
        for (int num : candies) {
            sum += num;
        }
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> ratings = {1, 2, 5, 2, 4};
    cout << solution.candy(ratings);
    
    return 0;
}
