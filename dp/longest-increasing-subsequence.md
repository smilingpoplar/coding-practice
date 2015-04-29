### 最长递增子序列

求字符串s的最长递增子序列的长

设Ai表示**以s[i]为尾**的最长递增子序列，考虑最后元素s[n-1]能否分别和这前n-1个Ai构成更长递增序列：

                  max{ lis(s,i)+1 }  i=[0..n-2], s[n-1]>=s[i]
    lis(s,n-1)= {
                  1                  otherwise

最后所求：
    
    max{ lis(s,i) }  i=[0..n-1]

看递归式中变化的是n-1的位置，故

设lis[i]表示以s[i-1]为尾的最长递增子序列的长，根据递归式在自底向上时把n-1=>i,i=>j得

    lis[0..n-1] = 1
    lisMax = INT_MIN
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (s[i] >= s[j]) {
                if (lis[j]+1 > lis[i]) {
                    lis[i] = lis[j]+1;
                    if (lis[i] > lisMax) lisMax = lis[i];
                }
            }
        }
    }
    return lisMax;


