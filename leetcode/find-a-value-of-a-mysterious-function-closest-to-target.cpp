//
//  find-a-value-of-a-mysterious-function-closest-to-target
//  https://leetcode.com/problems/find-a-value-of-a-mysterious-function-closest-to-target/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int closestToTarget(vector<int>& arr, int target) {
        // func(arr,l,r)做范围与操作
        // 用set[r]记录所有arr[..r]的“范围与”结果，
        // set[r+1] = { set[r]中各数 & arr[r+1], arr[r+1] }
        unordered_set<int> set1;
        int ans = INT_MAX;
        for (int a : arr) {
            unordered_set<int> set2;
            set2.insert(a);
            for (auto x : set1) {
                set2.insert(x & a);
            }
            for (auto x : set2) {
                ans = min(ans, abs(x - target));
            }
            swap(set1, set2);
        }
        return ans;
    }
};

class Solution {
public:
    int closestToTarget(vector<int>& A, int target) {
        // 在数组子段B[lo..hi)记录以A[idx]结尾的、A[..idx]所有子段的AND结果
        // A[..idx+1]所有子段的AND结果为 {B[lo..hi)中各数 | A[idx+1], A[idx+1]}
        // AND值放入B中的顺序是 A[idx]、A[idx-1..idx]、A[idx-2..idx]...，一定单调递减，
        // 只需防止到达AND值极限后继续往里塞
        vector<int> B;
        int lo = 0, hi = 0;
        for (int a : A) {
            B.push_back(a);
            for (int i = lo; i < hi; i++) {
                int a2 = B[i] & a;
                // 防止到达AND值极限后继续往里塞
                if (a2 != B.back()) B.push_back(a2); 
            }
            lo = hi, hi = B.size();
        }
        
        int ans = INT_MAX;
        for (int b : B) {
            ans = min(ans, abs(b - target));
        }
        return ans;    
    }
};

int main(int argc, const char * argv[]) {    
    return 0;
}
