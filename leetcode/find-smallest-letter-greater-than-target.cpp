//
//  find-smallest-letter-greater-than-target
//  https://leetcode.com/problems/find-smallest-letter-greater-than-target/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int l = -1, u = letters.size();
        while (l + 1 < u) {
            int mid = l + (u - l) / 2;
            if (letters[mid] > target) {
                u = mid;
            } else {
                l = mid;
            }
        }
        if (u == letters.size()) return letters[0];
        return letters[u];
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
