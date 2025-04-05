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
        // 对于第一个数，若A[i]<A[j]，A[j]、A[k]递增，则A[i]、A[k]是更远的递增，A[i]优于A[j]
        // 即几何上的左下点占支配地位，未被支配的集合是递减序列
        // 对于第二个数，若A[j]<A[k]，A[i]、A[j]递增，则A[i]、A[k]是更远的递增，A[k]优于A[j]
        // 即几何上的右上点占支配地位，未被支配的集合是从右往左的递增序列
        // 双指针法
        const int N = A.size();
        stack<int> stk;  // 栈底固定为A[0]的递减栈
        for (int i = 0; i < N; i++) {
            if (stk.empty() || A[i] < A[stk.top()]) {
                stk.push(i);
            }
        }
        // 再从右往左A[j]与栈顶比较
        int ans = 0;
        for (int j = N - 1; j >= 0; j--) {
            while (!stk.empty() && A[j] >= A[stk.top()]) {
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
