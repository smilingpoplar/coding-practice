//
//  find-anagram-mappings
//  https://leetcode.com/problems/find-anagram-mappings/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    vector<int> anagramMappings(vector<int>& A, vector<int>& B) {
        unordered_map<int, int> mp;
        for (int i = 0; i < B.size(); i++) {
            mp[B[i]] = i;
        }
        
        vector<int> ans;
        for (int a : A) {
            ans.push_back(mp[a]);
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
