//
//  relative-ranks
//  https://leetcode.com/problems/relative-ranks/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        const int N = nums.size();
        vector<int> idx;
        for (int i = 0; i < N; i++)
            idx.push_back(i);
        sort(idx.begin(), idx.end(), [&](int i, int j) { return nums[i] > nums[j]; });

        vector<string> ans(N);
        for (int i = 0; i < N; i++)
            ans[idx[i]] = rankStr(i);
        return ans;
    }
    
    string rankStr(int idx) {
        if (idx == 0) return "Gold Medal";
        if (idx == 1) return "Silver Medal";
        if (idx == 2) return "Bronze Medal";
        return to_string(idx + 1);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
