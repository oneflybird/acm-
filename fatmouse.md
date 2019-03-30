# FatMouse's Speed
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 9   Accepted Submission(s) : 3
Special Judge
Problem Description
FatMouse believes that the fatter a mouse is, the faster it runs. To disprove this, you want to take the data on a collection of mice and put as large a subset of this data as possible into a sequence so that the weights are increasing, but the speeds are decreasing.


Input
Input contains data for a bunch of mice, one mouse per line, terminated by end of file. The data for a particular mouse will consist of a pair of integers: the first representing its size in grams and the second representing its speed in centimeters per second. Both integers are between 1 and 10000. The data in each test case will contain information for at most 1000 mice. Two mice may have the same weight, the same speed, or even the same weight and speed.


Output
Your program should output a sequence of lines of data; the first line should contain a number n; the remaining n lines should each contain a single positive integer (each one representing a mouse). If these n integers are m[1], m[2],..., m[n] then it must be the case that W[m[1]] < W[m[2]] < ... < W[m[n]] and S[m[1]] > S[m[2]] > ... > S[m[n]] In order for the answer to be correct, n should be as large as possible. All inequalities are strict: weights must be strictly increasing, and speeds must be strictly decreasing. There may be many correct outputs for a given input, your program only needs to find one.


Sample Input
6008 1300
6000 2100
500 2000
1000 4000
1100 3000
6000 2000
8000 1400
6000 1200
2000 1900


Sample Output
4
4
5
9
7



```cpp
#include<stdio.h>
int max2(int a,int b){
	return a>b?a:b;
}
//结构体快排，根据end标准升序排序
//结构体快排的思想与普通快拍稍有不同
struct mouse{
	int weight;
	int speed;
    int num;
}a[1001];


void qsort(int l,int r)
{
    int i=l;		//i为最左
    int j=r;		//j为最右
    int mid=a[(l+r)/2].speed; //中间的数为基准，即使之后mid位置上的数改变，基准数不变 ，一次排序之后小于mid的数排在mid左边
	struct mouse temp;
    while (i<j)		//i和j为同一个位置时或i在j右边时退出循环
    {
        while (a[j].speed>mid) j--;//那个先排无所谓
        while (a[i].speed<mid) i++;
        if (i<=j)		//必须要有等于号，目的为了i和j走一位
        {
            temp = a[i];
            a[i] = a[j];
            a[j] = temp;
            i++;
            j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}
int main(){
    int i = 0;
    while(scanf("%d %d",&a[i].weight,&a[i].speed)==2) i++;
	for(int j = 0;j<i;j++) a[j].num = j+1;
    qsort(0,i-1);
//    for(int h = 0;h<i;h++){
//    printf("%d %d %d\n",a[h].num,a[h].weight,a[h].speed);
//}
    int sum[1001] = {0};
    int ans[1001][1001]={0};
    int mmax = 0;
    int mark0 = 0;
    int mark = 0;
    int temp;
    int j;
    for(j = 0;j < i;j ++){
        sum[j] = 1;
        temp = j;
        for(int k = j-1;k >= 0;k --){
            if(a[k].weight > a[j].weight&&a[k].speed<a[j].speed){//坑1
                if(sum[k]+1>sum[j]){
                    sum[j] = sum[k] + 1;
                    temp = k;
                }
            }
        }
        //由temp转移到j
        ans[temp][j] = 1;
        if(mmax<sum[j]){
            mmax = sum[j];
            mark = j;
            mark0 = temp;//坑2 原本没有mark0变量直接用了temp
        }
    }
    printf("%d\n",mmax);
    printf("%d\n",a[mark].num);
    int ss = mark0;
    while(ss!=mark){
        printf("%d\n",a[ss].num);
		mark = ss;
        for(ss = 0;ss<=mark;ss++){
            if(ans[ss][mark] == 1){
                break;
            }
        }
    }

    return 0;
}
```
> 原本自认为对的优化有可能出现问题，需要多找几组测试数据
> 严格按照要求排序需要严格判断，排序相等也可能连在一起

# 一维数组存储路径
因为子最优解是确定的，所以prev一维数组就够了

```cpp
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

int dp[1009];
int prev[1009];
int maxer;
class mouse
{
	public:
		int weight;
		int speed;
		int num;
};

mouse tar[1009];

bool cmp(mouse a,mouse b)
{
	if(a.weight==b.weight)
	{
		return a.speed>b.speed;
	}
	else
		return a.weight<b.weight;

}

void print_rd(int i)
{
	if(maxer--)
	{
		print_rd(prev[i]);//递归输出
		cout<<tar[i].num+1<<endl;
	}
}

int main()
{
	int i=0;
	int tmpwei,tmpspd;
	while(cin>>tmpwei>>tmpspd)
	{
		tar[i].weight=tmpwei;
		tar[i].speed=tmpspd;
		tar[i].num=i;
		i++;
	}
	int countmouse=i,pos=0;
	maxer=-0x3f3f3f3f;

	sort(tar,tar+countmouse,cmp);

	for(int i=0;i<countmouse;i++)
	{
		dp[i]=1;
		prev[i]=i;
	}

	for(int i=0;i<countmouse;i++)
	{
		for(int j=0;j<i;j++)
		{
			if(tar[i].weight>tar[j].weight && tar[i].speed<tar[j].speed && dp[j]+1>dp[i])
			{
				dp[i]=dp[j]+1;
				prev[i]=j;
			}
			if(dp[i]>maxer)
			{
				maxer=dp[i];
				pos=i;
			}

		}
	}
	cout<<maxer<<endl;
	print_rd(pos);
	return 0;
}

---------------------
作者：mig_davidli
来源：CSDN
原文：https://blog.csdn.net/mig_davidli/article/details/10010229
版权声明：本文为博主原创文章，转载请附上博文链接！
输出路径的第二种方法：
不需要加二维数据，直接通过sum和weight的判断确定路径
```
