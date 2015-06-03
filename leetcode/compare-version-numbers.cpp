//
//  compare-version-numbers
//  https://leetcode.com/problems/compare-version-numbers/
//
//  Created by smilingpoplar on 15/6/3.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <sstream>

using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        istringstream iss1(version1);
        istringstream iss2(version2);
        while (iss1 || iss2) {
            int v1 = extractVersion(iss1);
            int v2 = extractVersion(iss2);
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }
        return 0;
    }
private:
    int extractVersion(istringstream &iss) {
        string token;
        if (!getline(iss, token, '.')) return 0;
        return stoi(token);
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    cout << solution.compareVersion("1.0", "1");
    
    return 0;
}