//
//  two-sum-ii-input-array-is-sorted
//  https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = numbers.size() - 1;
        while (i <= j) {
            if (numbers[i] + numbers[j] == target) {
                return { i + 1, j + 1 };
            } else if (numbers[i] + numbers[j] < target) {
                ++i;
            } else {
                --j;
            }
        }
        return { -1, -1 };
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
