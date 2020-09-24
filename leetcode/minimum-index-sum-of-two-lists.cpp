//
//  minimum-index-sum-of-two-lists
//  https://leetcode.com/problems/minimum-index-sum-of-two-lists/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        unordered_map<string, int> mp;
        for (int i = 0; i < list1.size(); i++) {
            mp[list1[i]] = i;
        }
        vector<string> ans;
        int minIndexSum = INT_MAX;
        for (int j = 0; j < list2.size(); j++) {
            if (!mp.count(list2[j])) continue;
            
            int indexSum = mp[list2[j]] + j;
            if (indexSum < minIndexSum) {
                minIndexSum = indexSum;
                ans = { list2[j] };
            } else if (indexSum == minIndexSum) {
                ans.push_back(list2[j]);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
