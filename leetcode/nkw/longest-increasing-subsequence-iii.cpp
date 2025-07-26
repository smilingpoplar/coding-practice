//
//  longest-increasing-subsequence-iii
//  NC91 最长上升子序列(三)
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> LIS(vector<int>& arr) {
        const int N = arr.size();
        vector<int> tails;        // 保存各长度LIS的最小尾元素，是个递增数组
        vector<int> indices;      // tails[i]元素的下标为indices[i]
        vector<int> prev(N, -1);  // prev[i]表示arr[i]的前驱下标
        for (int i = 0; i < N; i++) {
            auto it = lower_bound(tails.begin(), tails.end(), arr[i]);
            int idx = it - tails.begin();
            if (it != tails.end()) {  // 若找到，则用arr[i]替换该项（末尾变小、LIS长度不变）
                *it = arr[i];
                indices[idx] = i;
            } else {  // 若找不到，说明所有尾元素都<arr[i]，可扩展序列
                tails.push_back(arr[i]);
                indices.push_back(i);
            }
            // arr[i]元素放到tails[idx]，其前驱是tails[idx-1]
            if (idx > 0) prev[i] = indices[idx - 1];
        }

        // 还原LIS
        vector<int> ans;
        for (int i = indices.back(); i >= 0; i = prev[i]) {
            ans.push_back(arr[i]);
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};