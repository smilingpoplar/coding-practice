//
//  long-pressed-name
//  https://leetcode.com/problems/long-pressed-name/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int i = 0, j = 0;
        while (j < typed.size()) {
            if (typed[j] == name[i]) i++, j++;
            else if (j > 0 && typed[j] == typed[j-1]) j++;
            else return false;
        }
        return i == name.size();
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
