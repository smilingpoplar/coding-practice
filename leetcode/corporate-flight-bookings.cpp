//
//  corporate-flight-bookings
//  https://leetcode.com/problems/corporate-flight-bookings/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        // 边界计数
        vector<int> ans(n);
        for (auto &b : bookings) {
            ans[b[0]-1] += b[2]; // 1-based label
            if (b[1] < n) ans[b[1]] -= b[2];
        }
        for (int i = 1; i < n; i++) {
            ans[i] += ans[i-1];
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
