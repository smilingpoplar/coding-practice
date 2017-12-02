//
//  minimum-index-sum-of-two-lists
//  https://leetcode.com/problems/minimum-index-sum-of-two-lists/
//
//  Created by smilingpoplar on 17/12/02.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> m;
        for (int i = 0; i < list1.size(); i++) {
            m[list1[i]] = i;
        }
        int minIndexSum = INT_MAX;
        vector<string> ans;
        for (int j = 0; j < list2.size(); j++) {
            if (m.find(list2[j]) != m.end()) {
                int indexSum = m[list2[j]] + j;
                if (indexSum < minIndexSum) {
                    minIndexSum = indexSum;
                    ans = { list2[j] };
                } else if (indexSum == minIndexSum) {
                    ans.push_back(list2[j]);
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
