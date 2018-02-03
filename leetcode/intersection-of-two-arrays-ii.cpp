//
//  intersection-of-two-arrays-ii
//  https://leetcode.com/problems/intersection-of-two-arrays-ii/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> count;
        for (int num : nums1)
            count[num]++;
        
        vector<int> ans;
        for (int num : nums2) {
            if (count[num] > 0) {
                ans.push_back(num);
                count[num]--;
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
