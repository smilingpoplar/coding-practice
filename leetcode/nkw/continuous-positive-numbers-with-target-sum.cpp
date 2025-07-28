//
//  tower-of-hanoi
//  NC259 和为S的连续正数序列
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> FindContinuousSequence(int target) {
        vector<vector<int>> ans;
        int lo = 1, hi = 0;
        int sum = 0;           // [lo..hi]，初始为空
        while (hi < target) {  // hi取值范围 [1..target-1]
            if (sum > target) {
                sum -= lo;
                lo++;
            } else {
                if (sum == target) {
                    vector<int> seq;
                    for (int i = lo; i <= hi; i++) {
                        seq.push_back(i);
                    }
                    ans.push_back(seq);
                }

                hi++;
                sum += hi;
            }
        }

        return ans;
    }
};
