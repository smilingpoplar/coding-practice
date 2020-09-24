//
//  lemonade-change
//  https://leetcode.com/problems/lemonade-change/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int c5 = 0, c10 = 0;
        for (int bill : bills) {
            if (bill == 5) {
                c5++;
            } else if (bill == 10) {
                if (c5 == 0) return false;
                c5--;
                c10++;
            } else if (bill == 20) {
                if (c10 > 0 && c5 > 0) {
                    c10--;
                    c5--;
                } else if (c5 >= 3) {
                    c5 -= 3;
                } else {
                    return false;
                }
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
