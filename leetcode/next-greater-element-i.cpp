//
//  next-greater-element-i
//  https://leetcode.com/problems/next-greater-element-i/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& findNums, vector<int>& nums) {
        unordered_map<int, int> mp;
        stack<int> stk;
        for (int num : nums) {
            while (!stk.empty() && num > stk.top()) {
                mp[stk.top()] = num;
                stk.pop();
            }
            stk.push(num);
        }
        
        vector<int> ans;
        for (int num: findNums) {
            ans.push_back(mp.count(num) ? mp[num] : -1);
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
