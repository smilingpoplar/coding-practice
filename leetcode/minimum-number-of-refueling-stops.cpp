//
//  minimum-number-of-refueling-stops
//  https://leetcode.com/problems/minimum-number-of-refueling-stops/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 车油足够时不加油，只把加油站油量记入最大堆；车油不够时，从堆中取最大值加油。
        const int N = stations.size();
        int maxDist = startFuel; // 能行驶的最大距离
        priority_queue<int> pq;
        int ans = 0, idx = 0;
        while (true) {
            while (idx < N && stations[idx][0] <= maxDist) {
                pq.push(stations[idx][1]);
                idx++;
            }
            if (maxDist >= target) return ans;
            if (pq.empty()) return -1; // 无油可加

            int fuel = pq.top();  pq.pop();
            maxDist += fuel;
            ans++;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
