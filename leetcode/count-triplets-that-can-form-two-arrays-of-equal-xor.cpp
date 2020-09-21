//
//  count-triplets-that-can-form-two-arrays-of-equal-xor
//  https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/
//
//  Created by smilingpoplar on 18/01/19.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int countTriplets(vector<int>& arr) {
        const int N = arr.size();
        vector<int> prexor(N + 1, 0); // 前闭后开区间的xor
        for (int i = 0; i < N; i++) {
            prexor[i+1] = prexor[i] ^ arr[i];
        }
        // a==b => a^b==0 => prexor[k+1]==prexor[i]
        int ans = 0;
        for (int i = 0; i < N; i++) {
            for (int k = i + 1; k < N; k++) {
                if (prexor[k+1] == prexor[i]) {
                    ans += k - i; // j可取在(i,k]
                }
            }
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
