### 子集和问题

1. 数组a[n]中是否有些元素的和为m？a[n]的元素皆为正数

根据最后元素a[n-1]是否参与：

* 参与：hasSubsetSum(a, n, m) = hasSubsetSum(a, n-1, m - a[n-1])
* 不参与：hasSubsetSum(a, n, m) = hasSubsetSum(a, n-1, m)

递归基础：

* hasSubsetSum(a, 0, 1..m) = false
* hasSubsetSum(a, 0..n, 0) = true 

动态规划两条件：

> 最优子结构：找到递归公式和递归基础  
> 自底向上：填表，以表查询代替递归调用

设s[i,j]表示a[0..i-1]中有些元素的和为j，则：

    s[0,1..m] = false
    s[0..n,0] = true
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            s[i][j] = s[i-1][j];
            if (a[i-1] <= j) {
                s[i][j] |= s[i-1][j - a[i-1]];
            }
        }
    }
    return s[n, m]
