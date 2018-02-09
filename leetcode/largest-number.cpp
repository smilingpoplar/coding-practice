//
//  largest-number.cpp
//  https://leetcode.com/problems/largest-number/
//
//  Created by smilingpoplar on 15/4/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> v;
        for (auto num : nums) {
            v.push_back(to_string(num));
        }        
        sort(v.begin(), v.end(), [](const string &s1, const string &s2) {
            return s1 + s2 > s2 + s1;
        });
        
        // 以0开头的特例，如 [0, 0]
        if (v[0] == "0") return "0";
        ostringstream oss;
        for (auto &str : v) oss << str;
        return oss.str();
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums = {3, 30, 34, 5, 9};
    Solution solution;
    cout << solution.largestNumber(nums);
    
    return 0;
}
