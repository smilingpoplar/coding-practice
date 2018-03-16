//
//  intersection-of-two-arrays
//  https://leetcode.com/problems/intersection-of-two-arrays/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> st;
        for (int num : nums1)
            st.insert(num);
        
        vector<int> ans;
        for (int num : nums2) {
            if (st.count(num)) {
                ans.push_back(num);
                st.erase(num);
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
