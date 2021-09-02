//
//  kth-missing-positive-number
//  https://leetcode.com/problems/kth-missing-positive-number/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // 题目：找第k小的缺失自然数
        // 假设arr[i]全部>k，所求就是k；从左往右遇到arr[i]<=k，就递增k
        for (int num : arr) { // arr[]是递增数组
            if (num <= k) k++;
            else break;
        }
        return k;
    }    
};

class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        // 题目：找第k小的缺失自然数
        // 数组arr和缺失数组mis可拼成自然数序列，
        // 值arr[m]是自然数序列的第arr[m]个元素，又是数组arr的第m+1个元素，
        // 所以<=arr[m]的缺失数count(m)=arr[m]-(m+1)
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
        // <=arr[u]的缺失数首次有>=k个。
        // <=arr[u-1]的缺失数有count(u-1)=arr[u-1]-u个，
        // 比起需要的k个，还差k-(arr[u-1]-u)个，
        // 第k个缺失数为 arr[u-1]+(k-(arr[u-1]-u)) = u+k
        return u + k;
    }
    
    bool enough(int m, vector<int>& arr, int k) {
        return arr[m] - (m + 1) >= k;
    }
};


int main(int argc, const char * argv[]) {    
    return 0;
}
