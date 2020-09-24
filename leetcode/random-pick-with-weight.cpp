//
//  random-pick-with-weight
//  https://leetcode.com/problems/random-pick-with-weight/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
    vector<int> wsum;
public:
    Solution(vector<int> w) : wsum(w.size(), 0) {
        wsum[0] = w[0];
        for (int i = 1; i < w.size(); i++) {
            wsum[i] = wsum[i-1] + w[i];
        }
        srand(time(NULL));
    }
    
    int pickIndex() {
        int rnd = rand() % wsum.back();
        // 要rnd<wsum[i]，在wsum中找第一个>rnd的位置
        return upper_bound(wsum.begin(), wsum.end(), rnd) - wsum.begin();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
