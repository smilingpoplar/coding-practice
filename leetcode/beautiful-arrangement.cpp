//
//  beautiful-arrangement
//  https://leetcode.com/problems/beautiful-arrangement/
//
//  Created by smilingpoplar on 17/11/30.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countArrangement(int N) {
        vector<int> a(N + 1);
        for (int i = 1; i <= N; i++) {
            a[i] = i;
        }
        return permute(a, 1);
    }
    
    int permute(vector<int> &a, int index) {
        if (index >= a.size()) {
            return 1;
        }
        int count = 0;
        for (int i = index; i < a.size(); i++) {
            swap(a[index], a[i]);
            if (a[index] % index == 0 || index % a[index] == 0) {
                count += permute(a, index + 1);
            }
            swap(a[index], a[i]);
        }
        return count;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
