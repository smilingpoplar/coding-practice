//
//  minimum-cost-to-hire-k-workers
//  https://leetcode.com/problems/minimum-cost-to-hire-k-workers/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int K) {
        // paid[i]/paid[j] == quality[i]/quality[j]，paid[i]/quality[i] == paid[j]/quality[j]
        // 所以，K个人的单位质量报酬率应相等，整组报酬率由K个人中的最高期望报酬率决定
        const int N = quality.size();
        vector<pair<double, int>> workers;
        for (int i = 0; i < N; i++) {
            workers.push_back({ (double)wage[i] / quality[i], quality[i] });
        }
        sort(workers.begin(), workers.end());
        
        double ans = 1e9;
        int qsum = 0; // 整组quality之和
        priority_queue<int> pq; // quality最大堆
        for (auto &worker : workers) {
            qsum += worker.second;
            pq.push(worker.second);
            if (pq.size() > K) { qsum -= pq.top(); pq.pop(); }
            if (pq.size() == K) { ans = min(ans, qsum * worker.first); }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
