//
//  reorder-array
//  NC77 调整数组顺序使奇数位于偶数前面(一)
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> reOrderArray(vector<int>& array) {
        // 冒泡排序，奇数往前移
        const int N = array.size();
        for (int i = 0; i < N - 1; i++) {
            for (int j = N - 1; j > i; j--) {
                if (array[j] % 2 == 1 && array[j - 1] % 2 == 0) {  // j处奇数，j-1处偶数
                    swap(array[j], array[j - 1]);
                }
            }
        }
        return array;
    }
};
