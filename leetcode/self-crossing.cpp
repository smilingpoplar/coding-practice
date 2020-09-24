//
//  self-crossing
//  https://leetcode.com/problems/self-crossing/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
/*               i-2
    case 1 : i-1┌─┐
                └─┼─>i
                 i-3
                 
                    i-2
    case 2 : i-1 ┌────┐
                 └─══>┘i-3
                 i  i-4      (i overlapped i-4)

    case 3 :    i-4
               ┌──┐ 
               │i<┼─┐
            i-3│ i-5│i-1
               └────┘
                i-2

*/
public:
    // https://leetcode.com/problems/self-crossing/discuss/79131/Java-Oms-with-explanation
    bool isSelfCrossing(vector<int>& x) {
        // x[d]表示沿某个方向的线长
        for (int i = 3; i < x.size(); i++) {
            // case 1：与i-3相交，最终往右往上移了
            if (x[i] >= x[i-2] && x[i-3] >= x[i-1]) return true;
            // case 2：与i-4相交
            if (i >= 4 && x[i-1] == x[i-3] && x[i] + x[i-4] >= x[i-2]) return true;
            // case 3：与i-5相交
            if (i >= 5 && x[i-2] >= x[i-4] && x[i] + x[i-4] >= x[i-2] && 
                x[i-3] >= x[i-1] && x[i-1] + x[i-5] >= x[i-3]) return true;
        }
        return false;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
