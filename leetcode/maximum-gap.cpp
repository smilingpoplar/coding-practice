//
//  maximum-gap
//  https://leetcode.com/problems/maximum-gap/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        if (nums.size() < 2) return 0;
        // 因为 maxGap >= ceiling((max-min)/(n-1))，设后者为bucketSize，由于每个桶是半开半闭区间，
        // 桶内gap < bucketSize <= maxGap，maxGap不可能在桶内取得，只能在桶间取得，每个桶只需保留其最大最小值
        // 桶的个数为 (max-min)/bucketSize + 1（+1是因为桶是半闭半开区间）
        // 数num会落在第 (num-min)/bucketSize 个桶中
        
        // min和max
        int min = INT_MAX;
        int max = INT_MIN;
        for (int num : nums) {
            if (num < min) min = num;
            if (num > max) max = num;
        }
        if (max == min) return 0;

        int bucketSize = ceil(double(max - min) / (nums.size() - 1));
        int bucketCount = (max - min) / bucketSize + 1;
        vector<vector<int>> buckets(bucketCount);
        for (int num : nums) {
            int idx = (num - min) / bucketSize;
            auto &bucket = buckets[idx];
            // 每个桶只需保留其最大最小值
            if (bucket.empty()) {
                bucket.push_back(num);
                bucket.push_back(num);
            } else {
                if (num < bucket[0]) bucket[0] = num; // bucket min
                if (num > bucket[1]) bucket[1] = num; // bucket max
            }
        }
        
        // 在桶间求maxGap，首桶和尾桶肯定非空
        int maxGap = INT_MIN;
        int prev = 0;
        for (int i = 1; i < bucketCount; i++) {
            if (buckets[i].empty()) continue;
            int gap = buckets[i][0] - buckets[prev][1];
            if (gap > maxGap) maxGap = gap;
            prev = i;
        }
        return maxGap;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> array = {1, 1, 1, 1, 1, 5, 5, 5, 5, 5};
    Solution solution;
    cout << solution.maximumGap(array);

    return 0;
}
