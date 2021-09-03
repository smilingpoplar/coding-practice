//
//  count-of-smaller-numbers-after-self
//  https://leetcode.com/problems/count-of-smaller-numbers-after-self/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        // 要看数的右边，所以不能移动数字，在索引数组idx上归并排序
        const int N = nums.size();
        vector<int> idx;
        for (int i = 0; i < N; i++) {
            idx.push_back(i);
        }
        vector<int> ans(N, 0);
        mergeSort(nums, idx, 0, N - 1, ans);
        return ans;
    }

    void mergeSort(vector<int> &nums, vector<int> &idx, int l, int r, vector<int> &ans) {
        if (l >= r) return;
        int mid = l + (r - l) / 2;
        mergeSort(nums, idx, l, mid, ans);
        mergeSort(nums, idx, mid + 1, r, ans);

        vector<int> merged(r - l + 1);
        // 两指针同向遍历，从两数组末端开始比较
        int i = mid, j = r, k = r - l;
        while (i >= l && j > mid) {
            if (nums[idx[i]] > nums[idx[j]]) {
                ans[idx[i]] += j - mid; // 位置[mid+1..j]与i逆序
                merged[k--] = idx[i--];
            } else {
                merged[k--] = idx[j--];
            }
        }
        while (i >= l) merged[k--] = idx[i--];
        while (j > mid) merged[k--] = idx[j--];
        for (int k = 0; k < merged.size(); k++) {
            idx[l + k] = merged[k];
        }
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
