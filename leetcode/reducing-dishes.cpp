//
//  reducing-dishes
//  https://leetcode.com/problems/reducing-dishes/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxSatisfaction(vector<int>& satis) {
        // 选一个子序列，和自然数序列相乘
        // 先排序，比如-1 1 3，从后往前取，
        // 取1个时              3*1
        // 取2个时        1*1 + 3*2
        // 取3个时 -1*1 + 1*2 + 3*3
        // 与上一行差值为 satis[i] + sufsum[i+1..]
        sort(begin(satis), end(satis));
        const int N = satis.size();
        int cur = 0, sufsum = 0, ans = 0;
        for (int i = N - 1; i >= 0; i--) {
            cur += satis[i] + sufsum;
            ans = max(ans, cur);
            sufsum += satis[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
