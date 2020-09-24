//
//  bulb-switcher-iii
//  https://leetcode.com/problems/bulb-switcher-iii/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numTimesAllBlue(vector<int>& light) {
        // light[i]往左全亮时变蓝，
        // max(light[..i])=i+1
        int maxL = INT_MIN, ans = 0;
        for (int i = 0; i < light.size(); i++) {
            maxL = max(maxL, light[i]);
            if (maxL == i + 1) ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
