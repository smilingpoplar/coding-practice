//
//  fair-candy-swap
//  https://leetcode.com/problems/fair-candy-swap/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
        // sumA-a+b = sumB-b+a, b = a-(sumA-sumB)/2
        int sum = 0;
        for (int a : A) sum += a;
        for (int b : B) sum -= b;
        sum /= 2; // (sumA-sumB)/2
        
        unordered_set<int> st;
        for (int b : B) st.insert(b);
        for (int a : A) {
            int toFind = a - sum;
            if (st.count(toFind)) return {a, toFind};
        }
        return {-1, -1};
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
