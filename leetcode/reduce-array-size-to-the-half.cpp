//
//  reduce-array-size-to-the-half
//  https://leetcode.com/problems/reduce-array-size-to-the-half/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSetSize(vector<int>& arr) {
        unordered_map<int, int> count;
        for (auto num : arr) {
            count[num]++;
        }

        int total = 0;
        multiset<int> st;
        for (auto &e : count) {
            st.insert(e.second);
            total += e.second;
        }
        
        int ans = 0;
        int removed = 0;
        for (auto it = st.rbegin(); it != st.rend(); it++) {
            removed += *it;
            ans++;
            if (removed >= total / 2) break;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
