//
//  permutation-sequence
//  https://leetcode.com/problems/permutation-sequence/
//
//  Created by smilingpoplar on 15/5/28.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        // 假设由[0,n-1]这n个元素构成排列，首元素固定后剩余的元素有(n-1)!种排列，
        // 所以每种首元素有(n-1)!种排列，第k个（从0开始的第k个）排列的首元素是 k/(n-1)!
        if (n <= 0) return "";
        int count = factorial(n);
        if (k < 1 || k > count) return "";

        vector<char> letters;
        for (int i = 0; i < n; ++i) {
            letters.push_back(i + '1');
        }
        
        --k; // k从0开始计数
        ostringstream result;
        while (n > 0) {
            count /= n; // (n-1)!
            int index = k / count;
            result << letters[index]; // 排列的首元素
            letters.erase(letters.begin() + index);
            k %= count;
            --n;
        }
        return result.str();
    }
private:
    int factorial(int n) {
        int product = 1;
        for (int i = 1; i <= n; ++i) {
            product *= i;
        }
        return product;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.getPermutation(3, 5);
    
    return 0;
}
