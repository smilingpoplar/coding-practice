//
//  heaters
//  https://leetcode.com/problems/heaters/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int findRadius(vector<int>& houses, vector<int>& heaters) {
        // 各house找最近的heater
        sort(heaters.begin(), heaters.end());
        
        int ans = INT_MIN;
        for (int house : houses) {
            int dist = INT_MAX;
            auto it = lower_bound(heaters.begin(), heaters.end(), house);
            if (it != heaters.end()) dist = min(dist, *it - house);
            if (it != heaters.begin()) dist = min(dist, house - *(it - 1));
            ans = max(ans, dist);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
