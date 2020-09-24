//
//  shortest-subarray-to-be-removed-to-make-array-sorted
//  https://leetcode.com/problems/shortest-subarray-to-be-removed-to-make-array-sorted/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        // 从开头找非递减子段[0..left]，从尾巴找非递减子段[right..N-1]
        // 粗略些只保留一个，精细些这两个子段可拼成最终的非递减数组[0..i]+[j..N-1]
        const int N = arr.size();
        int left = 0;
        while (left + 1 < N && arr[left] <= arr[left + 1]) left++;
        if (left == N - 1) return 0;
        int right = N - 1;
        while (right > left && arr[right - 1] <= arr[right]) right--;
        // 若只保留一个
        int ans = min(N - left - 1, right);
        // 用两指针法拼成[0..i]+[j..N-1]，删除无序子段[i+1..j-1]
        int i = 0, j = right;
        while (i <= left && j < N) {
            if (arr[j] >= arr[i]) {
                ans = min(ans, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
