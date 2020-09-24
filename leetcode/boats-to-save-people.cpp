//
//  boats-to-save-people
//  https://leetcode.com/problems/boats-to-save-people/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());
        int i = 0, j = (int)people.size() - 1;
        int ans = 0;
        while (i <= j) {
            ans++;
            if (people[i] + people[j] <= limit) i++;
            j--;
        }
        return ans;
    }
};

int main(int argc, const char * argv[]) {
    return 0;
}
