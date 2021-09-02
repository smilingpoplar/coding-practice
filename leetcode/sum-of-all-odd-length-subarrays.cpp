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
    int sumOddLengthSubarrays(vector<int>& A) {
        // 看A[i]对奇数长子段贡献了多少值
        // 左边包含A[i]的子段A[..i]有i+1个，右边包含A[i]的子段A[i..]有N-i个，包含A[i]的子段共(i+1)*(N-i)个。
        // 设包含A[i]的奇数子段有odd个，偶数子段有even个，由举例归纳的、应该没错的结论为 odd=even或even+1。
        // 注：比如举例统计[1 2 3 4 5]中包含2的长度1子段数、长度2子段数、长度3子段数...，
        // 所以奇数长子段有 odd = ((i+1)*(N-i)+1)/2个
        const int N = A.size();
        int ans = 0;
        for (int i = 0; i < N; i++) {
            ans += ((i+1)*(N-i)+1)/2 * A[i];
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
