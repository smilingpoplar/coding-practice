//
//  positions-of-large-groups
//  https://leetcode.com/problems/positions-of-large-groups/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        const int N = S.size();
        vector<vector<int>> ans;
        int left = 0;
        for (int i = 0; i < N; i++) {
            if (i == 0 || S[i] != S[i-1]) left = i;
            if (i == N - 1 || S[i] != S[i+1]) {
                if (i - left + 1 >= 3) ans.push_back({left, i});
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
