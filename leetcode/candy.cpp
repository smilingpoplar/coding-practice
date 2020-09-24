//
//  candy
//  https://leetcode.com/problems/candy/
//
//  Copyright (c) 2015 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int candy(vector<int>& ratings) {
        const int N = ratings.size();
        vector<int> candies(N, 1);
        for (int i = 1; i < N; i++) { // 只考虑比左侧分高的
            if (ratings[i] > ratings[i-1]) {
                candies[i] = candies[i-1] + 1;
            }
        }
        for (int i = N - 2; i >= 0; i--) { // 只考虑比右侧分高的
            if (ratings[i] > ratings[i+1]) {
                candies[i] = max(candies[i], candies[i+1] + 1);
            }
        }

        int sum = 0;
        for (int candy : candies)
            sum += candy;
        return sum;
    }
};

int main(int argc, const char * argv[]) {
    Solution solution;
    vector<int> ratings = {1, 2, 5, 2, 4};
    cout << solution.candy(ratings);
    
    return 0;
}
