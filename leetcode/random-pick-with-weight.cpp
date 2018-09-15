//
//  random-pick-with-weight
//  https://leetcode.com/problems/random-pick-with-weight/
//
//  Created by smilingpoplar on 15/6/7.
//  Copyright (c) 2015年 YangLe. All rights reserved.
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
            wsum[i] += wsum[i-1] + w[i];
        }
        srand(time(NULL));
    }
    
    int pickIndex() {
        int rnd = rand() % wsum.back();
        // 因为rnd<wsum[N-1]，<号没带=，所以在wsum中找>rnd的第一个
        return upper_bound(wsum.begin(), wsum.end(), rnd) - wsum.begin();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
