//
//  tower-of-hanoi
//  NC67 汉诺塔问题
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<string> getSolution(int n) {
        vector<string> ans;
        hanoi(n, "left", "mid", "right", ans);
        return ans;
    }

    void hanoi(int n, const string &a, const string &b,
               const string &c, vector<string> &ans) {
        if (n == 0) {
            return;
        }
        hanoi(n - 1, a, c, b, ans);
        ans.push_back("move from " + a + " to " + c);
        hanoi(n - 1, b, a, c, ans);
    }
};
