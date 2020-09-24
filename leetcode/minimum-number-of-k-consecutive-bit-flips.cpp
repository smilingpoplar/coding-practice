//
//  minimum-number-of-k-consecutive-bit-flips
//  https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // 若翻转A[i..i+K-1]，将i放入双端队列q
        // 对A[i]有影响的是有效窗口[i-K+1,i-1]内的翻转次数q.size()
        // 若A[i]==0&&q.size()%2==0 或 A[i]==1&&q.size()%2==1，要翻转
        const int N = A.size();
        int ans = 0;
        deque<int> q;
        for (int i = 0; i < N; i++) {
            if (!q.empty() &&  q.front() < i - K + 1) {
                q.pop_front();
            }
            if (A[i] == q.size() % 2) { // 要翻转
                if (i + K - 1 >= N) return -1;
                q.push_back(i);
                ans++;
            }
        }
        return ans;
    }
};

/*
class Solution {
public:
    int minKBitFlips(vector<int>& A, int K) {
        // flipKFrom[i]表示翻转A[i..i+K-1]，
        // influ表示flipKFrom[i-K+1..i-1]对A[i]的影响，
        // 若A[i]==0&&influ==0 或 A[i]==1&&influ==1，要翻转
        const int N = A.size();
        vector<int> flipKFrom(N, 0);
        int influ = 0, ans = 0;
        for (int i = 0; i < N; i++) {
            if (A[i] == influ) {
                if (i + K - 1 >= N) return -1;
                flipKFrom[i] = 1;
                ans++;
            }
            
            influ ^= flipKFrom[i];
            if (i - K + 1 >= 0) influ ^= flipKFrom[i - K + 1];
        }
        return ans;
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
