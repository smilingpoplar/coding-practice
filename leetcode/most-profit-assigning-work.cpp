//
//  most-profit-assigning-work
//  https://leetcode.com/problems/most-profit-assigning-work/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& difficulty, vector<int>& profit, vector<int>& worker) {
        const int N = difficulty.size();
        vector<pair<int, int>> jobs;
        for (int i = 0; i < N; i++) {
            jobs.push_back({difficulty[i], profit[i]});
        }
        sort(jobs.begin(), jobs.end());
        // 能力低的先找，能力高的至少能找当前已知的最好工作
        sort(worker.begin(), worker.end());
        
        int i = 0, currBest = 0, ans = 0;
        for (int ability : worker) {
            while (i < N && jobs[i].first <= ability) {
                currBest = max(currBest, jobs[i].second);
                i++;
            }
            ans += currBest;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
