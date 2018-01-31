//
//  jewels-and-stones
//  https://leetcode.com/problems/jewels-and-stones/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int numJewelsInStones(string J, string S) {
        set<char> jewels;
        for (char j : J) {
            jewels.insert(j);
        }
        
        int ans = 0;
        for (char s : S) {
            if (jewels.find(s) != jewels.end()) ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
