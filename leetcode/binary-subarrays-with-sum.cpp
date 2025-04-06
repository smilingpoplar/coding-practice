//
//  binary-subarrays-with-sum
//  https://leetcode.com/problems/binary-subarrays-with-sum/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int target) {
        return atMost(A, target) - atMost(A, target - 1);
    }

    int atMost(vector<int>& A, int target) {
        if (target < 0) return 0;
        const int N = A.size();

        int sum = 0, ans = 0;
        for (int hi = 0, lo = 0; hi < N; hi++) {
            sum += A[hi];
            while (sum > target) {
                sum -= A[lo++];
            }
            ans += hi - lo + 1;
        }
        return ans;
    }
};

/*
class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int target) {
        unordered_map<int, int> presum = {{0,1}}; // sum=>count
        int runningSum = 0;

        int ans = 0;
        for (int a : A) {
            runningSum += a;
            // 需S=runningSum-toFind
            int toFind = runningSum - target;
            if (presum.count(toFind)) ans += presum[toFind];
            presum[runningSum]++;
        }
        return ans;
    }
};
*/

int main(int argc, const char* argv[]) {
    return 0;
}
