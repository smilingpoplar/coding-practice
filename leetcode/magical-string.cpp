//
//  magical-string
//  https://leetcode.com/problems/magical-string/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int magicalString(int n) {
        string s("122");
        int i = 2;
        while (s.size() < n) {
            s.append(string(s[i] - '0', s.back()^3)); // '1' 0011 0001，'2' 0011 0010，'1'^'2'==3
            i++;
        }
        return count(s.begin(), s.begin() + n, '1');
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
