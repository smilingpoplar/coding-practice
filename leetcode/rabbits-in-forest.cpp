//
//  rabbits-in-forest
//  https://leetcode.com/problems/rabbits-in-forest/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        map<int, int> count;
        for (int num : answers) 
            count[num]++;
        // 1 => 2          2 => 3
        // 1 1 => 2        2 2 => 3
        // 1 1 1 => 4      2 2 2 => 3
        // 1 1 1 1 => 4    2 2 2 2 => 6
        // 每x+1个分一组，一共ceil(count[x]/(x+1))=(count[x]+x)/(x+1)组
        int ans = 0;
        for (auto &e : count) {
            int x = e.first;
            ans += (count[x] + x) / (x+1) * (x+1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
