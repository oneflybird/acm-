# Common Subsequence
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 4   Accepted Submission(s) : 3
Problem Description
A subsequence of a given sequence is the given sequence with some elements (possible none) left out. Given a sequence X = <x1, x2, ..., xm> another sequence Z = <z1, z2, ..., zk> is a subsequence of X if there exists a strictly increasing sequence <i1, i2, ..., ik> of indices of X such that for all j = 1,2,...,k, xij = zj. For example, Z = <a, b, f, c> is a subsequence of X = <a, b, c, f, b, c> with index sequence <1, 2, 4, 6>. Given two sequences X and Y the problem is to find the length of the maximum-length common subsequence of X and Y.
The program input is from a text file. Each data set in the file contains two strings representing the given sequences. The sequences are separated by any number of white spaces. The input data are correct. For each set of data the program prints on the standard output the length of the maximum-length common subsequence from the beginning of a separate line.


Sample Input
abcfbc abfcab
programming contest
abcd mnp


Sample Output
4
2
0

> 对于最长公共子序列(LCS)，是典型的动态规划问题，对于这个问题，可以用如下思路来解答。
如：X{x1, x2, x3, ... },Y{y1, y2, y3, ...};
1.当x1 = y1时，则此时已找到一个相同的值，故接下来只需求{x2, x3, x4, ...}和{y2, y3, y4, ...}的LCS。
2.当x1 != y1时，则此时X和Y的LCS是下面两个LCS的最大值：
  {x2, x3, x4, ...}和{y1, y2, y3, y4, ...}的LCS，
  或者{x1, x2, x3, x4, ...}和{y2, y3, y4, ...}的LCS。

> 参考http://www.cnblogs.com/shuaiwhu/archive/2011/05/27/2065040.html

```c++
#include<stdio.h>
#include<math.h>
#include<string.h>
int main(){
    char a[1001];
    char b[1001];
    int a1[1001][1001]={0};
    int max = 0;
    while(scanf("%s %s",&a,&b)==2){
        int m = strlen(a);
        int n = strlen(b);
        for(int i = 1;i<=m;i++){
            for(int j = 1;j<=n;j++){
                //重点 状态转移方程
                if(a[i-1]==b[j-1]){
                    a1[i][j] = a1[i-1][j-1]+1;
                }else if(a1[i-1][j]>a1[i][j-1]){
                    a1[i][j] = a1[i-1][j];
                }else{
                    a1[i][j] = a1[i][j-1];
                }
        }
    }
    printf("%d\n",a1[m][n]);

}
    return 0;
}
```
尽管做了几道dp题看到这道水题还是有点懵，首先要确定了子状态最优是否可以达到目标状态最优，子状态是什么，目标状态是什么？（可以用类似递归的思路来分析），在确定之后分析方向应该是**转移方程是什么**

> 补充 最短子序列内容
```cpp
    //c[m][n]值为最短子序列的长度
    //用result来保存逆序LCS，通过c[m][n]的值与c[m - 1][ n - 1]，c[m][n - 1]，c[m - 1][n]来判断
    int len = c[m][n];
    char* result = new char[len + 1];
    int count = len;
    while (m > 0 && n > 0) {
        if (c[m][n] == c[m - 1][ n - 1] + 1 && x[m - 1] == y[n - 1]) {
            result[--count] = x[m - 1];
            m--;
            n--;
        } else if (c[m][n] == c[m][n - 1]) {
            n--;
        } else {
            m--;
        }
        result[len] = '\0';
    }
```
