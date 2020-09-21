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
        return atMost(A, K) - atMost(A, K-1);
    }
    
    int atMost(vector<int>& A, int K) {
        const int N = A.size();
        unordered_map<int, int> cnt; // num=>count
        int ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            if (cnt[A[hi]]++ == 0) K--;
            while (K < 0) {
                if (--cnt[A[lo]] == 0) K++;
                lo++;
            }
            ans += hi - lo + 1;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int subarraysWithKDistinct(vector<int>& A, int K) {
        const int N = A.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        // 设以hi结尾的包含K个不同元素的窗口最长为[lo1..hi]、最短为[lo2..hi]，
        // lo1<=lo2，这里有lo2-lo1+1个窗口
        for (int hi = 0, lo1 = 0, lo2 = 0; hi < N; hi++) {
            cnt[A[hi]]++;
            if (cnt.size() == K + 1) {
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
*/

int main(int argc, const char * argv[]) {    
    return 0;
}
