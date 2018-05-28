//
//  k-th-smallest-in-lexicographical-order
//  https://leetcode.com/problems/k-th-smallest-in-lexicographical-order/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findKthNumber(int n, int k) {
        int curr = 1;
        while (k > 1) {
            int count = countNums(curr, n);
            if (k > count) { // 走右兄弟节点
                curr++;
                k -= count;
            } else { // 走最左子节点
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    
    // 计算前缀为prefix的数有多少个
    // 累加[prefix, prefix+1)、[prefix*10, (prefix+1)*10)、[prefix*100, (prefix+1)*100)、...
    // 其中每个区间都限制在[1,n]
    int countNums(int prefix, int n) {
        int cnt = 0;
        long start = prefix, end = prefix + 1;
        while (start <= n) {
            cnt += min(end, n + 1L) - start; // [start, min(end,n+1))
            start *= 10;
            end *= 10;
        }
        return cnt;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
