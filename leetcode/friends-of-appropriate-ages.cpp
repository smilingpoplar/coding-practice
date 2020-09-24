//
//  friends-of-appropriate-ages
//  https://leetcode.com/problems/friends-of-appropriate-ages/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numFriendRequests(vector<int>& ages) {
        unordered_map<int, int> cnt;
        for (int age : ages) cnt[age]++;
        
        int ans = 0;
        for (auto &eA : cnt) {
            int ageA = eA.first, cntA = eA.second;
            for (auto &eB : cnt) {
                int ageB = eB.first, cntB = eB.second;
                if (ageB <= 0.5 * ageA + 7) continue;
                if (ageB > ageA) continue;
                if (ageB > 100 && ageA < 100) continue;
                if (ageA != ageB) ans += cnt[ageA] * cnt[ageB];
                else ans += cnt[ageA] * (cnt[ageA] - 1); // 不能和自己交朋友
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
