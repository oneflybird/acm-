# Frogs' Neighborhood

##### Time Limit : 10000/5000ms (Java/Other)   Memory Limit : 20000/10000K (Java/Other)

##### Total Submission(s) : 5   Accepted Submission(s) : 1

##### Special Judge

Problem Description

未名湖附近共有*N*个大小湖泊*L*1, *L*2, ..., *Ln*(其中包括未名湖)，每个湖泊*Li*里住着一只青蛙*Fi*(1 ≤ *i* ≤ *N*)。如果湖泊*Li*和*Lj*之间有水路相连，则青蛙*Fi*和*Fj*互称为邻居。现在已知每只青蛙的邻居数目*x*1, *x*2, ..., *xn*，请你给出每两个湖泊之间的相连关系。

 

Input

<p>第一行是测试数据的组数<i>T</i>(0 ≤ <i>T</i> ≤ 20)。每组数据包括两行，第一行是整数N(2 < <i>N</i> < 10)，第二行是<i>N</i>个整数，<i>x</i><sub>1</sub>, <i>x</i><sub>2</sub>,..., <i>x</i><sub>n</sub>(0 ≤ <i>x<sub>i</sub></i> ≤ <i>N</i>)。</p>

 

Output

<p>对输入的每组测试数据，如果不存在可能的相连关系，输出"NO"。否则输出"YES"，并用<i>N</i>×<i>N</i>的矩阵表示湖泊间的相邻关系，即如果湖泊<i>i</i>与湖泊<i>j</i>之间有水路相连，则第<i>i</i>行的第<i>j</i>个数字为1，否则为0。每两个数字之间输出一个空格。如果存在多种可能，只需给出一种符合条件的情形。相邻两组测试数据之间输出一个空行。</p>

 

Sample Input

```
3
7
4 3 1 5 4 2 1 
6
4 3 1 4 2 0 
6
2 3 1 1 2 1 
```

 

Sample Output

```
YES
0 1 0 1 1 0 1 
1 0 0 1 1 0 0 
0 0 0 1 0 0 0 
1 1 1 0 1 1 0 
1 1 0 1 0 1 0 
0 0 0 1 1 0 0 
1 0 0 0 0 0 0 

NO

YES
0 1 0 0 1 0 
1 0 0 1 1 0 
0 0 0 0 0 1 
0 1 0 0 0 0 
1 1 0 0 0 0 
0 0 1 0 0 0 
```

 # 题解

```c++
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct time{
	int step;
	int num;
}a[11];
void qsort(int l,int r)
{
    int i=l;		//i为最左 
    int j=r;		//j为最右 
    int mid=a[(l+r)/2].num; //中间的数为基准，即使之后mid位置上的数改变，基准数不变 ，一次排序之后小于mid的数排在mid左边 
    int temp;
    while (i<j)		//i和j为同一个位置时或i在j右边时退出循环 
    {
        while (a[j].num>mid) j--;//那个先排无所谓 
        while (a[i].num<mid) i++;
        if (i<=j)		//必须要有等于号，目的为了i和j走一位 
        {
            temp=a[i].num;
            a[i].num=a[j].num;
            a[j].num=temp;
            temp=a[i].step;
            a[i].step=a[j].step;
            a[j].step=temp;
            i++;
            j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}
int main(){
	int n;
	cin >> n;
	int num;
	while(n -- > 0){
		cin>>num;
		int i = 1;
	int xv[11];	
		while(i <= num){
			cin >> a[i].num;
			a[i].step = i;
			xv[i] = a[i].num;
			i ++;
		}
		qsort(1,num);
//		for(int i = 1;i <= num;i ++){
//			printf("%d %d\n",a[i].num,a[i].step);
//		}
		//初始化 
		int cnt[11] = {0};
		int map[11][11]; 
		for(int i = 1;i <= num;i ++){
			for(int j = 1;j <= num;j ++){
				map[i][j] = 0;
			}
		}
		int flag = 0;
		while(a[num].num!=0){
			int k = a[num].num;
			int aa = 1;
			while(aa <= k){
				a[num-aa].num -= 1;
				map[a[num].step][a[num-aa].step] = 1;
				map[a[num-aa].step][a[num].step] = 1;
				aa++;
			}
			a[num].num = 0;
			if(a[num-aa+1].num<0){
				flag = 1;
				break;
			}
				qsort(1,num);
		}
//		for(int i = 1;i <= num;i ++){
//				for(int j = 1;j <= num;j ++){
//					printf("%d ",map[i][j]);
//				}
//				printf("\n");
//			}
		if(flag == 0){
			printf("YES\n");
			for(int i = 1;i <= num;i ++){
				for(int j = 1;j <= num;j ++){
					if(j==1){
						printf("%d",map[i][j]);
					}else{
						printf(" %d",map[i][j]);
					}
				}
				printf("\n");
			}
		}else{
			printf("NO\n");
		}
		printf("\n");
		
	}
	
	return 0;
} 
```

> 说明：运用了结构体，排序，和Havel-Hakimi定理

> Havel-Hakimi定理：由非负数组成的非增序列s：d1,d2,d3,...,dn(n>=2, d1>=1)是可图的，当且仅当序列s1:d2-1,d3-1,d4-1,...,d(d1+1)-1, d(d1+2),...,dn是可图的。
>
> 比如说：
>
> 给定序列为4 3 1 4 2 0，我们对其按非增序列排序，得到4 4 3 2 1 0，删除首项4，对其后4项每项减1，得到3 2 1 0 0，
>
> 对此再排序，再次删除首项，得到序列2 1 -1 0，由于一个图里面的度不可能为负数，所以这个图无法构成图。
>
> 而对于能构成图的，每次减去1的点对应的下标与被删去的首项对应的下标构成通路，这道题就解出来了。

## 可进行优化部分

```c++
for(int i = 0; i < n; ++i){
            for(int j = 1; j <= p[0].x; ++j){
                --p[j].x;
                nei[p[0].id][p[j].id] = 1;
                nei[p[j].id][p[0].id] = 1;
                if(p[j].x < 0) flag = 0;
            }
            p[0].x = 0;
            sort(p, p + n);
        }

--------------------- 
作者：_Wilbert 
来源：CSDN 
原文：https://blog.csdn.net/snow_me/article/details/52012871 
版权声明：本文为博主原创文章，转载请附上博文链接！
```

# 坑

在解题中，一开始想到的是用深度搜索来做，但做了半天没成功，这题貌似不适合用dfs，然后想到从低到高排序，先把数目最少的邻居按顺序填充，在这过程中如果邻居已满则跳过，失败告终，然后尝试用同样的思路从高到低排序，这种情况下sample数据可以通过，然而提交上去还是wa，由此可见，此思路依旧存在漏洞，在某种情况下用这种思路会让有的本可以凑满邻居的frog的邻居无法凑满，然后百度之后才找到了Havel-Hakimi定理成功ac。虽然在这个过程中浪费了5 6个小时，但是对于Havel-Hakimi的定理却有了更好的理解。（苦笑