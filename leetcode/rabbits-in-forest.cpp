//
//  rabbits-in-forest
//  https://leetcode.com/problems/rabbits-in-forest/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        // 数x每组有x+1个，共有ceil(count[x]/(x+1)) = (count[x]+x)/(x+1)组，
        // 所以报数x的兔子数为 (count[x]+x)/(x+1)*(x+1)
        unordered_map<int, int> count;
        for (int num : answers) count[num]++;

        int ans = 0;
        for (auto &e : count) {
            int x = e.first;
            ans += (count[x] + x) / (x + 1) * (x + 1);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
