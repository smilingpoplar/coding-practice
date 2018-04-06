//
//  minimize-max-distance-to-gas-station
//  https://leetcode.com/problems/minimize-max-distance-to-gas-station/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

/*
class Solution {
public:
    // 复杂度O(KlgN)，这里K很大，超时
    double minmaxGasDist(vector<int>& stations, int K) {
        // 贪婪法，将站加到站间距离最大的那个区间
        // pair: dist, stations_added_count
        auto cmp = [](pair<double,int> &a, pair<double,int> &b) {
            return a.first / (a.second + 1) < b.first / (b.second + 1);
        };
        priority_queue<pair<double, int>, vector<pair<double, int>>, decltype(cmp)> pq(cmp); 
        for (int i = 0; i + 1 < stations.size(); i++) {
            pq.push({stations[i+1] - stations[i], 0});
        }
        for (int i = 0; i < K; i++) {
            auto curr = pq.top(); pq.pop();
            curr.second += 1;
            pq.push(curr);
        }
        auto curr = pq.top();
        return curr.first / (curr.second + 1);
    }
};
*/

class Solution {
public:
    double minmaxGasDist(vector<int>& stations, int K) {
        // 用二分法猜D值，猜log(maxGuess-minGuess)次。对某个D值，要使所有的站间距离d<=D，
        // 原来的区间i中要添加 ceil(interval[i]/D) -1 = floor(interval[i]/D) 个站，O(n)时间知道总共添加多少站。
        // 设possible(D)为真表示添加<=K个站可使所有站间距离<=D。
        double lo = 0, hi = 1e8;
        while (hi - lo > 1e-6) {
            double mid = (hi + lo) / 2;
            if (possible(mid, stations, K)) {
                hi = mid;
            } else {
                lo = mid;
            }
        }
        return hi;
    }
    
    bool possible(double D, vector<int>& stations, int K) {
        int count = 0;
        for (int i = 0; i + 1 < stations.size(); i++) {
            count += (stations[i+1] - stations[i]) / D;
        }
        return count <= K;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}