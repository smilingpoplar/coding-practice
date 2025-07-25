//
//  check-if-a-string-contains-all-binary-codes-of-size-k
//  https://leetcode.com/problems/check-if-a-string-contains-all-binary-codes-of-size-k/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    bool hasAllCodes(string s, int k) {
        const int N = s.size();
        const int TARGET_SIZE = 1 << k;
        unordered_set<string> st;
        // TARAGET_SIZE是k长的所有可能，一定有st.size()<=TARGET_SIZE
        for (int i = 0; i + k <= N && st.size() < TARGET_SIZE; i++) {
            st.insert(s.substr(i, k));
        }
        return st.size() == TARGET_SIZE;
    }
};

int main(int argc, const char* argv[]) {
    return 0;
}
