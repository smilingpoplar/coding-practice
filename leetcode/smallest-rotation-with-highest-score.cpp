//
//  smallest-rotation-with-highest-score
//  https://leetcode.com/problems/smallest-rotation-with-highest-score/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int bestRotation(vector<int>& A) {
        // 看例子：
        //        num: 2 3 1 4 0
        //   k=0, idx: 0 1 2 3 4
        //   k=1, idx: 4 0 1 2 3
        //   k=2, idx: 3 4 0 1 2
        //   k=3, idx: 2 3 4 0 1
        //   k=4, idx: 1 2 3 4 0
        // num<=idx时得分，对于数num求它的得分k值区间，最多重叠区间数就是最大得分数
        // 数num从索引num开始得分，到索引N-1为止，对应k值在减小
        // 数num从索引idx变成索引num，左移idx-num次，对应k值(idx-num+N)%N
        //              变成索引N-1，左移idx-(N-1)次，对应k值(idx+1)%N
        // 所以，将[ (idx+1)%N .. (idx-num+N)%N ]范围的得分都+1
        // 范围加：将加法记在[left,right)的前闭后开边界上，变成求前缀和
        const int N = A.size();
        vector<int> count(N , 0);
        for (int i = 0; i < N; i++) {
            int left = (i + 1) % N;
            int right = (i - A[i] + 1 + N) % N;
            count[left]++, count[right]--;
            // left>right时有两个区间：[left,N)和[0,right)，不需count[N]--，补上count[0]++
            if (left > right) count[0]++;
        }
        
        int bestScore = -1, bestK = 0;
        int score = 0;
        for (int i = 0; i < N; i++) {
            score += count[i];
            if (score > bestScore) {
                bestScore = score;
                bestK = i;
            }
        }
        return bestK;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
