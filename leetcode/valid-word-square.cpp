//
  //  valid-word-square
  //  https://leetcode.com/problems/valid-word-square/
//
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        for (int i = 0; i < words.size(); i++) {
            for (int j = 0; j < words[i].size(); j++) {
                // words[j][i]的下标要合法
                if (j >= words.size() || i >= words[j].size() || words[i][j] != words[j][i]) return false;
            }
        }
        return true;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
