//
//  last-moment-before-all-ants-fall-out-of-a-plank
//  https://leetcode.com/problems/last-moment-before-all-ants-fall-out-of-a-plank/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int getLastMoment(int n, vector<int>& left, vector<int>& right) {
        int maxL = INT_MIN, maxR = INT_MIN;
        for (int l : left) {
            maxL = max(maxL, l);
        }
        for (int r : right) {
            maxR = max(maxR, n - r);
        }
        return max(maxL, maxR);
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
