### 最长公共子序列

求字符串s和t的最长公共子序列的长

考虑最后一个字符是否相等：

* 相等：lcs(s, m, t, n) = lcs(s, m-1, t, n-1)
* 不相等：lcs(s, m, t, n) = max{ lcs(s, m, t, n-1), lcs(s, m-1, t, n) }

递归基础：

* lcs(s, 0, t, 0..n) = 0
* lcs(s, 0..m, t, 0) = 0

看递归公式中变化的是m和n的位置，故

设lcs[i][j]表示s[0..i-1]和t[0..j-1]的最长公共子序列，有：

    lcs[0][0..n] = 0
    lcs[0..m][0] = 0
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i-1] == t[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            } else {
                lcs[i][j] = max( lcs[i][j-1], lcs[i-1][j] );
            }
        }
    }
    return lcs[m][n];

