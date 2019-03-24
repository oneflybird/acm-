# Quoit Design
> Time Limit : 10000/5000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 125   Accepted Submission(s) : 26
Problem Description
Have you ever played quoit in a playground? Quoit is a game in which flat rings are pitched at some toys, with all the toys encircled awarded.
In the field of Cyberground, the position of each toy is fixed, and the ring is carefully designed so it can only encircle one toy at a time. On the other hand, to make the game look more attractive, the ring is designed to have the largest radius. Given a configuration of the field, you are supposed to find the radius of such a ring.
Assume that all the toys are points on a plane. A point is encircled by the ring if the distance between the point and the center of the ring is strictly less than the radius of the ring. If two toys are placed at the same point, the radius of the ring is considered to be 0.


>Input
The input consists of several test cases. For each case, the first line contains an integer N (2 <= N <= 100,000), the total number of toys in the field. Then N lines follow, each contains a pair of (x, y) which are the coordinates of a toy. The input is terminated by N = 0.


> Output
For each test case, print in one line the radius of the ring required by the Cyberground manager, accurate up to 2 decimal places.


> Sample Input
2
0 0
1 1
2
1 1
1 1
3
-1.5 0
0 0
0 1.5
0


> Sample Output
0.71
0.00
0.75


```c++
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct time{
	int start;
	int end;
}a[100000];

void qsort(int l,int r)
{
    int i=l;		//i为最左
    int j=r;		//j为最右
    int mid=a[(l+r)/2].end; //中间的数为基准，即使之后mid位置上的数改变，基准数不变 ，一次排序之后小于mid的数排在mid左边
    int temp;
    while (i<j)		//i和j为同一个位置时或i在j右边时退出循环
    {
        while (a[j].end>mid) j--;//那个先排无所谓
        while (a[i].end<mid) i++;
        if (i<=j)		//必须要有等于号，目的为了i和j走一位
        {
            temp=a[i].end;
            a[i].end=a[j].end;
            a[j].end=temp;
            temp=a[i].start;
            a[i].start=a[j].start;
            a[j].start=temp;
            i++;
            j--;
        }
    }
    if (l<j) qsort(l,j);
    if (i<r) qsort(i,r);
}
int main(){
    int n;
    while(scanf("%d",&n)==1){
        for(int i = 0; i< n;i ++){
            cin>>a[i].end>>a[i].start;
        }
        //按照x排序
        qsort(0,n);

    }
    return 0;
}
```
> 这是一道高性能的题目，卡了半天a不过去的原因是cin读入比scanf时间长（真的非常非常坑），此题先将x排序获得左右两边的最小值，然后判断一点在左和一点在右的最小值。为什么最后只用判断这个点参考这篇文章https://blog.csdn.net/lishuhuakai/article/details/9161843
