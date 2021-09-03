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
    Solution(vector<int> w) {
        partial_sum(begin(w), end(w), back_inserter(wsum));
        srand(time(NULL));
    }
    
    int pickIndex() {
        // 按概率选中某项 <=> 从左往右按累计概率选中某项（从左往右保证了排除掉前面的累计概率，只剩当前项的概率）
        int rnd = rand() % wsum.back();
        // 要rnd<wsum[i]，在wsum中找第一个>rnd的位置
        return upper_bound(begin(wsum), end(wsum), rnd) - begin(wsum);
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
