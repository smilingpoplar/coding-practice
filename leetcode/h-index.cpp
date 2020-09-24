//
//  h-index
//  https://leetcode.com/problems/h-index/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {   
        // h-index定义：(引用数>=h的论文)的数量>=h
        // 按引用数分桶，>N的都算到count[N]上
        const int N = citations.size();
        vector<int> count(N + 1, 0);
        for (int c : citations) {
            if (c >= N) count[N]++;
            else count[c]++;
        }
        int sum = 0;
        for (int h = N; h >= 0; h--) { // h>=0、N-h>=0
            sum += count[h];
            if (sum >= h) return h;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
