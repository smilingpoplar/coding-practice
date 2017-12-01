//
//  distribute-candies
//  https://leetcode.com/problems/distribute-candies/
//
//  Created by smilingpoplar on 17/12/01.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    // 糖果种类数kind>=n/2时，妹妹最多获得种类数n/2；
    // kind<n/2时，把各种类都给妹妹，妹妹最多获得种类数kind
    int distributeCandies(vector<int>& candies) {
        set<int> s;
        for (int candy : candies) {
            s.insert(candy);
        }
        return min(candies.size() / 2, s.size());
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
