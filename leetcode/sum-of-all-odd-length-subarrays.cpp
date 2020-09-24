//
//  sum-of-all-odd-length-subarrays
//  https://leetcode.com/problems/sum-of-all-odd-length-subarrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        // 看arr[i]对奇数长子段贡献了多少值
        // arr[i]左边有子段[[0,i]..i]，共i+1个
        // 右边有子段[i..[i,N-1]]，共N-i个
        // 所以包含A[i]的子段共(i+1)*(N-i)个，
        // 其中奇数长子段有((i+1)*(N-i)+1)/2个
        const int N = arr.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += ((i+1)*(N-i)+1)/2 * arr[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
