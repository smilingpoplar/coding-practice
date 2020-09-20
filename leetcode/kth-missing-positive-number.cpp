//
//  kth-missing-positive-number
//  https://leetcode.com/problems/kth-missing-positive-number/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // 找第k小的缺失数
        // 猜一个数x，看<=x的缺失数有多少个
        // 猜的数不妨从arr[]中选arr[m]，看<=arr[m]的缺失数个数

        // 数组arr和缺失数组mis拼成自然数数组all，
        // 值arr[m]是数组all的第arr[m]个元素，又是数组arr的第m+1个元素，
        // 所以是缺失数组mis的第arr[m]-(m+1)个元素，
        // 即<=arr[m]的缺失数有count=arr[m]-(m+1)个，...(1)式
        // 因为arr[m]比m增加得快，count(m)是关于m的递增函数，
        // 条件式enough(m){count(m)>=k}满足二分搜索的条件形式[0..0 1..1]
        int l = -1, u = arr.size();
        while (l + 1 < u) {
            int m = l + (u - l) / 2;
            if (enough(m, arr, k)) {
                u = m;
            } else {
                l = m;
            }
        }
        // <=arr[u]的缺失数首次有>=k个，从前一个数arr[u-1]开始数，
        // 根据(1)式<=arr[u-1]的缺失数有arr[u-1]-u个，
        // 比起需要的k个，还差k-(arr[u-1]-u)个，
        // arr[u-1]+(k-(arr[u-1]-u)) = u+k
        return u + k;
    }
    
    bool enough(int m, vector<int>& arr, int k) {
        return arr[m] - (m + 1) >= k;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
