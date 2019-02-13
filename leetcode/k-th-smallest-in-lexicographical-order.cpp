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
            } else { // 不是当前节点，走最左子节点
                curr *= 10;
                k--;
            }
        }
        return curr;
    }
    
    // 以数p为根的子树含多少[1,n]间的数？
    // 可累加[p,p+1)、[p *10,(p+1) *10)、[p *100,(p+1) *100)、... 与[1,n]重合的部分
    int countNums(int p, long n) {
        int count = 0;
        long start = p, end = p + 1;
        while (start <= n) {
            count += min(end, n + 1) - start;
            start *= 10, end *= 10;
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
