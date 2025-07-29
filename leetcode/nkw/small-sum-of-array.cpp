//
//  small-sum-of-array
//  NC349 计算数组的小和
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    long long calArray(vector<int>& nums) {
        // 归并排序的思路
        const int N = nums.size();
        int l = 0, h = N - 1;
        return mergeSort(nums, l, h);
    }

    long long mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return 0;
        int mid = l + (h - l) / 2;
        long long ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, h);

        // 组间统计
        for (int i = l; i <= mid; i++) {
            // nums[mid+1..h]中找第一个>=nums[i]的数
            auto it = lower_bound(begin(nums) + mid + 1, begin(nums) + h + 1, nums[i]);
            int j = it - begin(nums);
            // (i,j), (i,j+1), ..., (l,h) 都满足 <=
            if (i >= l) ans += nums[i] * (h - j + 1);
        }

        merge(nums, l, mid, h);
        return ans;
    }

    // 归并已排序的 nums[l..mid] 和 nums[mid+1..h]
    void merge(vector<int>& nums, int l, int mid, int h) {
        vector<int> merged(h - l + 1);
        int i = l, j = mid + 1, k = 0;
        while (i <= mid && j <= h) {
            if (nums[i] < nums[j]) {
                merged[k++] = nums[i++];
            } else {
                merged[k++] = nums[j++];
            }
        }
        while (i <= mid) merged[k++] = nums[i++];
        while (j <= h) merged[k++] = nums[j++];
        for (int k = 0; k < merged.size(); k++) {
            nums[l + k] = merged[k];
        }
    }
};