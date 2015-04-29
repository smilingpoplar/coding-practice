### 最长公共子串

求字符串s和t的最长公共子串的长

设Ai表示**以A[i]结尾**的子串A[0..i]，得子问题：求Si和Tj的最长公共子串

原问题的答为：max{ Si和Tj的最长公共子串 }  i=[0..m-1],j=[0..n-1]

子问题根据s[i]和t[j]是否相等：

* 相等：lcs(s, i, t, j) = 1 + lcs(s, i-1, t, j-1)
* 不相等：lcs(s, i, t, j) = 0

看递归式中变化的是i和j的位置，故

设lcs[i][j]表示Si和Tj的最长公共子串的长

    int lcsMax = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i] == t[j]) {
                if (i == 0 || j == 0) lcs[i][j] = 1;
                else lcs[i][j] = 1 + lcs[i-1][j-1];
                if (lcs[i][j] > lcsMax) {
                    lcsMax = lcs[i][j];
                }
            } else {
                lcs[i][j] = 0;
            }
        }
    }
    return lcsMax;
