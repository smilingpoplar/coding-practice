//
//  minimum-number-of-refueling-stops
//  https://leetcode.com/problems/minimum-number-of-refueling-stops/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // 贪婪法
        // 车油足够时不加油，只把加油站油量记入最大堆；车油不够时，从堆中取最大值加油。
        const int N = stations.size();
        int idx = 0;
        int dist = startFuel; // 能行驶的最大距离
        priority_queue<int> pq;
        int ans = 0;
        while (true) {
            while (idx < N && stations[idx][0] <= dist) {
                pq.push(stations[idx][1]);
                idx++;
            }
            if (dist >= target) return ans;
            if (pq.empty()) return -1; // 无油可加

            int fuel = pq.top();  pq.pop();
            dist += fuel;
            ans++;
        }
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
