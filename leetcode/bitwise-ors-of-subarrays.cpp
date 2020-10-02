//
//  bitwise-ors-of-subarrays
//  https://leetcode.com/problems/bitwise-ors-of-subarrays/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // 在数组B[lo..hi)记录以A[idx]结尾的、A[..idx]所有子段的OR结果
        // A[..idx+1]所有子段的OR结果为 {B[lo..hi)中各数 | A[idx+1], A[idx+1]}
        // OR值放入B中的顺序是 A[idx]、A[idx-1..idx]、A[idx-2..idx]...，OR值范围越广越大，
        // 一定单调递增，只需防止到达OR值极限后继续往里塞
        vector<int> B;
        int lo = 0, hi = 0;
        for (int a : A) {
            B.push_back(a);
            for (int i = lo; i < hi; i++) {
                int a2 = B[i] | a;
                // 防止到达OR值极限后继续往里塞
                if (a2 != B.back()) B.push_back(a2); 
            }
            lo = hi;
            hi = B.size();
        }
        return unordered_set<int>(begin(B), end(B)).size();
    }
};

/*
class Solution {
public:
    int subarrayBitwiseORs(vector<int>& A) {
        // 用set[r]记录A[l]~A[r]子段的ORs结果
        // set[r+1]为 {set[r]中各数 | A[r+1], A[r+1]}
        unordered_set<int> set1, set2, ans;
        for (int a : A) {
            set2 = {a};
            for (int x : set1) 
                set2.insert(x | a);
            ans.insert(set2.begin(), set2.end());
            swap(set1, set2);
        }
        return ans.size();
    }
};
*/

int main(int argc, const char * argv[]) {
    return 0;
}
