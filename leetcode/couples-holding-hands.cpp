//
//  couples-holding-hands/
//  https://leetcode.com/problems/couples-holding-hands//
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int ans = 0;
        for (int i = 0; i < row.size(); i += 2) {
            int couple = row[i] ^ 1;
            if (row[i+1] ==  couple) continue;
            int j = i + 2;
            while (j < row.size() && row[j] != couple) ++j;
            row[j] = row[i+1];
            row[i+1] = couple;
            ans++;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
