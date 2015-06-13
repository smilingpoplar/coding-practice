//
//  median-of-two-sorted-arrays
//  https://leetcode.com/problems/median-of-two-sorted-arrays/
//
//  Created by smilingpoplar on 15/6/13.
//  Copyright (c) 2015年 YangLe. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &a, vector<int> &b) {
        // 参考：https://leetcode.com/discuss/11174/share-my-iterative-solution-with-o-log-min-n-m
        // 先找第k=(M+N+1)/2小的数，k从1开始计数。基本想法是 任意a[i]都可以在O(1)时间内判断它是不是第k小的数
        // 因为若a[i]是第k小的数，它要刚好大于k-1个数，而a[i]已经大于a中它的前i个数，只要它再刚好大于b中前j=k-1-i个数，
        // 即 b[j-1]<=a[i]<=b[j]，a[i]就是第k小的数；同理，a[i-1]<=b[j]<=a[i]，b[j]就是第k小的数
        
        // 对a做二分搜索，不变式：第k小数的候选x a[l]<=x<=a[r] && l<=r
        // 若a[i]<b[j-1]，a[i]最多大于b中的b[0,j-2]，最多大于总共i+j-1=k-2个数，应继续在a[i+1,M-1]中找（l=i+1，可能找到可能找不到）
        // 若a[i]>=b[j-1]，a[i]至少大于b中的b[0,j-1]，至少大于总共i+j=k-1个数，应继续在a[0,i]中找（r=i，肯定找得到）
        
        // 边界条件 0<=i<=min(k-1,M-1)，代入i=k-1-j，得 max(0,k-M)<=j<=k-1
        // 要使j有效，需k-1<=N-1，得 M<=N（这里计算的时候取实值k=(M+N)/2），所以当M>N时,交换a和b（重点1）
        // 直观上，无脑先做M<=N处理，肯定会简化处理逻辑
        // 确保M<=N后，边界条件成 0<=i<=M-1<=k-1，0<=k-M<=j<=k-1<=N-1
        
        const int M = (int)a.size();
        const int N = (int)b.size();
        if (M > N) return findMedianSortedArrays(b, a);
        
        // 二分搜索，为避免-1<=j-1<=N-2的越界问题，改搜第k+1小的数！（重点2）
        // 这时j=k-i，不变式：第k+1小数的候选y a[l]<=y<=a[r] && l<=r
        // 若a[i]<b[j-1]，a[i]最多大于总共i+j-1=k-1个数，应继续在a[i+1,M-1]中找
        // 若a[i]>=b[j-1]，a[i]至少大于总共i+j=k个数，应继续在a[0,i]中找
        // 边界条件 0<=i<=M-1<=k-1，代入i=k-j，得 1<=k-M+1<=j<=k<=N，j-1边界合格
        
        // 为表示第k+1小数的候选y不在a中的情况，引入假想的哨兵 a[M]>=y（重点3）
        // 因为只有在l=i+1时可能找不到导致越界，所以只需要右边的哨兵a[M]。因为i<r==M，程序并不实际访问到a[M]
        int k = (M + N + 1) / 2;
        int l = 0;
        int r = M; // a[M]是哨兵
        while (l < r) {
            int i = l + (r - l) / 2;
            int j = k - i;
            if (a[i] < b[j - 1]) {
                l = i + 1;
            } else {
                r = i;
            }
        }
        // 最终l==r，l指向第k+1小数的候选（在a中的话）或a[M]（不在a中的话）
        // 所以，第k+1小的数是a[l]（在a中的话）或b[k-l]（不在a中的话）
        
        // 中位数在下面四个数中产生：a[l-1]、b[k-l-1]、a[l]、b[k-l]，0<=l<=M，0<=k-l<=N
        // 若M+N是奇数，median = max(a[l-1],b[k-l-1])
        int num1 = max((l >= 1) ? a[l - 1] : INT_MIN, (k - l - 1 >= 0) ? b[k - l - 1] : INT_MIN);
        if ((M + N) & 0x01) return num1;
        // 若M+N是偶数，median是四个数的中间两个的平均，median = (max(a[l-1],b[k-l-1]) + min(a[l],b[k-l])) * 0.5
        int num2 = min(l < M ? a[l] : INT_MAX, k - l < N ? b[k - l] : INT_MAX);
        return (num1 + num2) * 0.5;
    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums1 = {200};
    vector<int> nums2 = {100,101,102,103,104,105};
    Solution solution;
    cout << solution.findMedianSortedArrays(nums1, nums2);
    
    return 0;
}
