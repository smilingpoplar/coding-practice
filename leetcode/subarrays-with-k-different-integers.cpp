//
//  subarrays-with-k-different-integers
//  https://leetcode.com/problems/subarrays-with-k-different-integers/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        // 伸缩滑动窗口
        const int N = A.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        // 设以hi结尾的包含K个不同元素的窗口最长为[lo1..hi]、最短为[lo2..hi]，
        // lo1<=lo2，这里有lo2-lo1+1个窗口
        for (int lo1 = 0, lo2 = 0, hi = 0; hi < N; hi++) {
            cnt[A[hi]]++;
            if (cnt.size() == K + 1) { // 含K个不同元素的窗口已处理完
                cnt.erase(A[lo2]);
                lo2++;
                lo1 = lo2;
            }
            if (cnt.size() == K) {
                while (cnt[A[lo2]] > 1) { // 尽量缩短[lo2..hi]
                    cnt[A[lo2]]--;
                    lo2++;
                }
                ans += lo2 - lo1 + 1;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
