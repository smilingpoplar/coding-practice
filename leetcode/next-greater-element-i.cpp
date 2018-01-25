//
//  reverse-pairs
//  https://leetcode.com/problems/reverse-pairs/
//
//  Created by smilingpoplar on 17/11/27.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        stack<int> s;
        for (int num : nums) {
            while (!s.empty() && num > s.top()) {
                mp[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> ans;
        for (int num: findNums) {
            ans.push_back((mp.find(num) != mp.end()) ? mp[num] : -1);
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
