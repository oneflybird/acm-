# 不容易系列之(3)—— LELE的RPG难题
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 93   Accepted Submission(s) : 37
Problem Description
人称“AC女之杀手”的超级偶像LELE最近忽然玩起了深沉，这可急坏了众多“Cole”（LELE的粉丝,即&quot;可乐&quot;）,经过多方打探，某资深Cole终于知道了原因，原来，LELE最近研究起了著名的RPG难题:<br><br>有排成一行的ｎ个方格，用红(Red)、粉(Pink)、绿(Green)三色涂每个格子，每格涂一色，要求任何相邻的方格不能同色，且首尾两格也不同色．求全部的满足要求的涂法.<br><br>以上就是著名的RPG难题.<br><br>如果你是Cole,我想你一定会想尽办法帮助LELE解决这个问题的;如果不是,看在众多漂亮的痛不欲生的Cole女的面子上,你也不会袖手旁观吧?<br><br>


> Input
输入数据包含多个测试实例,每个测试实例占一行,由一个整数N组成，(0<n<=50)。<br>


> Output
对于每个测试实例，请输出全部的满足要求的涂法，每个实例的输出占一行。<br>


>Sample Input
1
2


>Sample Output
3
6

## 题解
```c++
#include<cstdio>

int dfs(int n){
    if(n==1){
        return 1;
    }else if(n==2){
        return 2;
    }else{
        return dfs(n-1)+dfs(n-2);
    }
}

int main(){
    int t;
    long long k[51];
    k[1] = 3;
    k[2] = 6;
    k[3] = 6;
    for(int i=4;i<=50;i++){
        k[i] = k[i-1]+2*k[i-2];
    }
    int a;
    while(scanf("%d",&a)==1){
        printf("%lld\n",k[a]);
    }


    return 0;
}
```
### 分析
**分为合法和不合法两种情况**
前n-2个已涂好后，涂第n-1个即有2种情况：
1. n-1的色与1的色不相同，那么n就是剩下的那个色，即f(n-1)
2. n-1的色与1的色一样，那么n的色就有2个色选择.即f(n-2)*2
