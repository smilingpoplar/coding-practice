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
        unordered_map<int, int> m;
        stack<int> s; // 栈顶最小的栈
        for (int num : nums) {
            while (!s.empty() && num > s.top()) {
                m[s.top()] = num;
                s.pop();
            }
            s.push(num);
        }
        
        vector<int> ans;
        for (int num: findNums) {
            ans.push_back((m.find(num) != m.end()) ? m[num] : -1);
        }
        return ans;        
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
