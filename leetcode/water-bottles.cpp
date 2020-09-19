//
//  water-bottles
//  https://leetcode.com/problems/water-bottles/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        // 比如3个空瓶=>1瓶水+1个空瓶，实际上2个空瓶=>1瓶水，但是
        // 要触发这个交换，需要手中持有1个空瓶，下面的(numBottles-1)就是持有1个空瓶
        return numBottles + (numBottles - 1) / (numExchange - 1);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
