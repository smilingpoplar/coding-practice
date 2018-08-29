//
//  maximize-distance-to-closest-person
//  https://leetcode.com/problems/maximize-distance-to-closest-person/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        // 首或尾若有连续k个0，dist=k；
        // 中间若有连续k个0，dist=(k+1)/2
        const int N = seats.size();
        int i = 0, j = N - 1;
        int zeros = 0, ans = 0;
        for (zeros = 0; !seats[i]; i++) zeros++;
        ans = max(ans, zeros); // 首
        for (zeros = 0; !seats[j]; j--) zeros++;
        ans = max(ans, zeros); // 尾  
        for (zeros = 0; i <= j; i++) { // 中间
            if (!seats[i]) {
                zeros++;
            } else {
                ans = max(ans, (zeros + 1) / 2);
                zeros = 0;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
