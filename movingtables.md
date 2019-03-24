## ACM-贪心之Moving Tables——hdu1050
Moving Tables

Problem Description
The famous ACM (Advanced Computer Maker) Company has rented a floor of a building whose shape is in the following figure.




The floor has 200 rooms each on the north side and south side along the corridor. Recently the Company made a plan to reform its system. The reform includes moving a lot of tables between rooms. Because the corridor is narrow and all the tables are big, only one table can pass through the corridor. Some plan is needed to make the moving efficient. The manager figured out the following plan: Moving a table from a room to another room can be done within 10 minutes. When moving a table from room i to room j, the part of the corridor between the front of room i and the front of room j is used. So, during each 10 minutes, several moving between two rooms not sharing the same part of the corridor will be done simultaneously. To make it clear the manager illustrated the possible cases and impossible cases of simultaneous moving.




For each room, at most one table will be either moved in or moved out. Now, the manager seeks out a method to minimize the time to move all the tables. Your job is to write a program to solve the manager’s problem.
Input
The input consists of T test cases. The number of test cases ) (T is given in the first line of the input. Each test case begins with a line containing an integer N , 1<=N<=200 , that represents the number of tables to move. Each of the following N lines contains two positive integers s and t, representing that a table is to move from room number s to room number t (each room number appears at most once in the N lines). From the N+3-rd line, the remaining test cases are listed in the same manner as above.
Output
The output should contain the minimum time in minutes to complete the moving, one per line.
Sample Input
3
4
10 20
30 40
50 60
70 80
2
1 3
2 200
3
10 100
20 80
30 50
Sample Output
10
20
30
## 题解一
> 分析：
一开始按照尾房间号进行排序，结果wa了，而且一眼看上去思路没有问题调试了很久，而之后按照首房间号排序成功ac，然后参考了此博文https://blog.csdn.net/huahua520amy/article/details/9714681，具体如下

>如果你说只给你一次移动的机会，要你找到移动尽可能多的房间，我这种按照尾数排序的方式跟活动安排的例子无异都是正确的，但是这题不一样，最终你是要将所有的需要移动的房间移完，对于活动安排这个例子，也就意味着你必须将活动节目表上的节目全部安排完，问你最少需要多少天，这是同样的概念。
在网上搜了题解，没有人说明到底为什么要按照房间首位置排序，当然我也没理由否认这是不行的，我按照房间尾数排序无非是我找到了这么一个理由——余留更多的走廊长度，所以我就选择了这个方法，后来找到了一个Case，也就是上面我放上去的测试数据，根据两种排序方式输出，*发现前面房间的移动情况会影响接下来的房间移动*，这两天想了一段时间也每个结果
我从另外一个角度想，如果按房间尾数排序的话，那么在第二次遍历的时候第一个找到的房间的起始号并不是最前的，这时不是最优的，你要从总体上来看，你以为每次找到尽可能多的房间，对一次的遍历从房间尾号排序确实达到了这样的目的，但你的整体目的不是这样的，因为你**最终还是要把所有的房间找完**，**并不是说仅是找最多的一次，你还要顾及后面的让每一次都尽可能找得更多的房间**。所以不管前几次怎样，你现在要找的这一次需要越靠前开始找。

> 看了这篇博文后，其实仍似懂非懂，但总结出**如果要求节目数量安排最多，按结束时间排序，但是如果要求节目占时间表的时长最长，就要按首时间排序了**

```c++
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
struct time{
	int start;
	int end;
}a[201];

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
    int t;
    cin >> t;
    while(t-->0){
        int n;
        cin >> n;
        for(int i = 0; i < n;i ++){
            cin>>a[i].end>>a[i].start;
            if(a[i].start%2==1){
                a[i].start += 1;
            }
            if(a[i].end%2 == 1){
                a[i].end += 1;
            }
            if(a[i].end>a[i].start){
            	int t = a[i].start;
            	a[i].start = a[i].end;
            	a[i].end = t;
			}
        }
        qsort(0,n-1);//从小到大按搬走房间排序
//         for(int i = 0;i < n;i ++){
//         	cout<<'\n'<<a[i].start<<"  "<<a[i].end<<endl;
//		 }
        int flag[201] = {0};
        int end = 1;
        int cnt = 0;
        int fy = a[0].end;
        while(end){
            end = 0;
            for(int i = 0;i < n;i ++){
                if(flag[i]) continue;
                //算起点
                if(end == 0){
                	fy = a[i].start;
                	flag[i] = 1;
                    end = 1;
//                	cout<<a[i].start<<" "<<a[i].end<<endl;
                	continue;
				}
                if(flag[i]==0){
	                if(a[i].end>fy){
                    	flag[i] = 1;
                    	fy = a[i].start;
//                    	cout<<a[i].start<<"  "<<a[i].end<<endl;
                    }
                }
            }
            if(end==0) break;
            cnt+= 10;
        }
        printf("%d\n",cnt);
    }

    return 0;
}
```
## 题解二
> 分析
假设从1到400（下标从1开始）的走廊是一条线段，每次搬一张桌子，假设从15号房间搬到25号房间，则线段15->25就重复了一次。然后另外再去搬一张桌子，假设这回从20号房间搬到30号房间，则线段20->30就重复了一次，相同的线段:20->25就重复了两次，问题转化为求最大重复次数。

>那就好办了，一个205大小的数组表示走廊位置(200个走廊位置)，初始化为0，如果15->25重复了一次，则对15,16,17,18,19,20的走廊位置都加上1，第二次线段20->30又重复了，则又对20....30的位置加1。全部完成后，找出走廊最大值的位置，乘以10分钟，就是所用时间！


```c++
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[205];
int main()
{
    int t,n;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        int start,finish;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&start,&finish);
            if(start>finish)
            {
                swap(start,finish);
            }
            start = (start+1)/2;
            finish = (finish+1)/2;
            for(int j=start;j<=finish;j++)
            {
                a[j]++;
            }
        }
        int MAX = 0;
        for(int i=0;i<205;i++)
        {
            if(a[i]>MAX)
            {
                MAX=a[i];
            }
        }
        printf("%d\n",MAX*10);
    }
    return 0;
}


---------------------
作者：边界流浪者
来源：CSDN
原文：https://blog.csdn.net/qq_16542775/article/details/46564797
版权声明：本文为博主原创文章，转载请附上博文链接！
```
