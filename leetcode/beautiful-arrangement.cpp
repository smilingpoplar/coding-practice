//
//  beautiful-arrangement
//  https://leetcode.com/problems/beautiful-arrangement/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) a[i] = i;
        return searh(a, 1);
    }
    
    int searh(vector<int> &a, int idx) {
        if (idx >= a.size()) return 1; // 得到一个有效解
        int count = 0;
        // 测试n个数的排列
        for (int i = idx; i < a.size(); i++) {
            swap(a[idx], a[i]);
            if (a[idx] % idx == 0 || idx % a[idx] == 0) {
                count += searh(a, idx + 1);
            }
            swap(a[idx], a[i]);
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
