//
//  verify-postorder-sequence-in-binary-search-tree
//  NC271 二叉搜索树的后序遍历序列
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        if (sequence.empty()) return false;
        const int N = sequence.size();
        return verify(sequence, 0, N - 1, INT_MIN, INT_MAX);
    }

    bool verify(vector<int> seq, int lo, int hi, int lower, int upper) {
        if (lo > hi) return true;
        int val = seq[hi];
        if (val <= lower || val >= upper) return false;

        int i = lo;
        while (seq[i] < val) i++;
        return verify(seq, lo, i - 1, lower, val) && verify(seq, i, hi - 1, val, upper);
    }
};