//
//  maximum-width-ramp
//  https://leetcode.com/problems/maximum-width-ramp/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        // 找相距最远的两个递增数
        // 对第一个数，若A[i]<A[j]，A[j]、A[k]递增，则A[i]、A[k]是更远的递增，
        // A[i]占优于A[j]，即几何上的左下点占优，所以从左到右扫描，<栈顶的占优
        // 对第二个数，若A[j]<A[k]，A[i]、A[j]递增，则A[i]、A[k]是更远的递增，
        // A[k]占优于A[j]，即几何上的右上点占优，所以从右往左扫描，>栈顶的占优
        // 两指针法
        const int N = A.size();
        stack<int> stk;
        for (int i = 0; i < N; i++) {
            if (stk.empty() || A[i] < A[stk.top()]) {  // 第一个数的占优选择
                stk.push(i);
            }
        }

        int ans = 0;
        for (int j = N - 1; j >= 0; j--) {                  // 从右往左扫描
            while (!stk.empty() && A[j] >= A[stk.top()]) {  // 第二个数的占优选择
                ans = max(ans, j - stk.top());
                stk.pop();
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        const int N = A.size();
        vector<int> rMax(N, 0);
        rMax[N - 1] = A[N - 1];
        for (int i = N - 2; i >= 0; i--) {
            rMax[i] = max(A[i], rMax[i + 1]);
        }

        int ans = 0;
        int lo = 0, hi = 0;
        while (hi < N) {
            while (lo < hi && A[lo] > rMax[hi]) {
                lo++;
            }
            ans = max(ans, hi - lo);
            hi++;
        }
        return ans;
    }
};
*/

/*
class Solution {
public:
    int maxWidthRamp(vector<int>& A) {
        const int N = A.size();
        multimap<int, int> mp; // num=>idx
        for (int i = 0; i < N; i++) {
            mp.insert({A[i], i});
        }

        int minIdx = INT_MAX, ans = 0;
        for (auto &e : mp) { // 按值递增遍历
            int idx = e.second;
            ans = max(ans, idx - minIdx);
            minIdx = min(minIdx, idx);
        }
        return ans;
    }
};
*/

int main(int argc, const char* argv[]) {
    return 0;
}
