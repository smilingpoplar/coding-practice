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

    int mergeSort(vector<int>& nums, int l, int h) {
        if (l >= h) return 0;
        int mid = l + (h - l) / 2;
        int ans = mergeSort(nums, l, mid) + mergeSort(nums, mid + 1, h);

        // 组间统计
        for (int j = mid + 1; j <= h; j++) {
            int i = mid;
            while (i >= l && nums[i] > nums[j]) i--;
            // (i,j), (i-1,j), ..., (l,j) 满足
            for (int x = l; x <= i; x++) {
                ans += nums[x];
            }
        }

        merge(nums, l, mid, h);
        return ans;
    }

    // 归并已排序的 nums[l,mid] 和 nums[mid+1,h]
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