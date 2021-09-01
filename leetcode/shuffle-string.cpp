//
//  shuffle-string
//  https://leetcode.com/problems/shuffle-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        const int N = s.size();
        for (int i = 0; i < N; i++) {
            while (i != indices[i]) {
                int j = indices[i];
                swap(indices[i], indices[j]);
                swap(s[i], s[j]);
            }
        }
        return s;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
