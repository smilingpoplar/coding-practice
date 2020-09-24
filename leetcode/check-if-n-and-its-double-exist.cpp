//
//  check-if-n-and-its-double-exist
//  https://leetcode.com/problems/check-if-n-and-its-double-exist/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        unordered_set<int> st;
        for (int a : arr) {
            if (st.count(a * 2) 
                || (a % 2 == 0 && st.count(a / 2)))
                return true;
            st.insert(a);
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
