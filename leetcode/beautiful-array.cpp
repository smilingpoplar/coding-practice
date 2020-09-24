//
//  beautiful-array
//  https://leetcode.com/problems/beautiful-array/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> beautifulArray(int N) {
        // 题目：两数位置之间不能存在它们的平均数
        // beautiful数组有性质：若A满足，A*2仍满足，A+c仍满足
        // 从数组[1]开始长度翻倍，数组前半为奇数A*2-1，后半为A*2
        vector<int> A({1});
        while (A.size() < N) {
           vector<int> tmp;
            for (int num : A) {
                int odd = num * 2 - 1;
                if (odd <= N) tmp.push_back(odd);
            }
            for (int num : A) {
                int even = num * 2;
                if (even <= N) tmp.push_back(even);
            }
            swap(A, tmp);
        }
        return A;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
