//
//  k-concatenation-maximum-sum
//  https://leetcode.com/problems/k-concatenation-maximum-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <numeric>

using namespace std;

class Solution {
public:
    int kConcatenationMaxSum(vector<int>& arr, int k) {
        // 最大子段和，如果arrSum<=0：
        //  1. 在arr中间，k=1
        //  2. 在两数组尾首，arr[suffix]+arr[prefix]，k=2
        // 如果arrSum>0：
        //  1. 在arr中间 + (k-1)*arrSum
        //  2. 在两数组尾首，arr[suffix]+arr[prefix]+(k-2)*arrSum
        // 总结：
        //  对k<=2，照常找最大子段和；
        //  对k>2且arrSum>0，再加上(k-2)*arrSum
        long maxendinghere = 0, maxsofar = 0;
        for (int i = 0; i < min(k, 2); i++) {
            for (int a : arr) {
                maxendinghere = max(maxendinghere + a, 0L);
                maxsofar = max(maxsofar, maxendinghere);
            }
        }

        const int MOD = 1e9 + 7;
        long arrSum = accumulate(begin(arr), end(arr), 0);
        if (k > 2 && arrSum > 0) {
            return (maxsofar + (k - 2) * arrSum) % MOD;
        }
        return maxsofar % MOD;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
