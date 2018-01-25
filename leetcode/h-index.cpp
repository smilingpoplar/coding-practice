//
//  h-index
//  https://leetcode.com/problems/h-index/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int hIndex(vector<int>& citations) {   
        // h指某个论文引用数，0<=h<=N
        const int N = citations.size();
        vector<int> count(N + 1, 0); // 各引用数有几篇论文，>N的引用数都算到count[N]上
        for (int citation : citations) {
            if (citation >= N) count[N]++;
            else count[citation]++;
        }
        int sum = 0;
        for (int i = N; i >= 0; i--) {
            sum += count[i];
            if (sum >= i) return i;
        }
        return 0;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
