Doing Homework again
Time Limit : 1000/1000ms (Java/Other)   Memory Limit : 32768/32768K (Java/Other)
Total Submission(s) : 53   Accepted Submission(s) : 32
Problem Description
Ignatius has just come back school from the 30th ACM/ICPC. Now he has a lot of homework to do. Every teacher gives him a deadline of handing in the homework. If Ignatius hands in the homework after the deadline, the teacher will reduce his score of the final test. And now we assume that doing everyone homework always takes one day. So Ignatius wants you to help him to arrange the order of doing homework to minimize the reduced score.


Input
The input contains several test cases. The first line of the input is a single integer T that is the number of test cases. T test cases follow. Each test case start with a positive integer N(1<=N<=1000) which indicate the number of homework.. Then 2 lines follow. The first line contains N integers that indicate the deadlines of the subjects, and the next line contains N integers that indicate the reduced scores.


Output
For each test case, you should output the smallest total reduced score, one line per test case.


Sample Input
3
3
3 3 3
10 5 1
3
1 3 1
6 2 3
7
1 4 6 4 2 4 3
3 2 1 7 6 5 4


Sample Output
0
3
5


Author
lcy


Source
2007省赛集训队练习赛（10）_以此感谢DOOMIII

```c++
#include<cstdio>
#include<iostream>
using namespace std;
struct time{
	int start;
	int end;
}a[1000];
int flag[1002];
int arrange_day(int i){
    if(i<=0){
        return 1;
    }
    if(flag[i]==0){
        flag[i] = 1;
        return 0;
    }else{
        if(arrange_day(i-1)) return 1;
        return 0;
    }
}

//普通快排
void quicksort(int l,int r){
	struct time temp = a[l];
	int i=l;
    int j=r;
	if(i>j){
		return;
	}
	while (i<j)
    {
        while (a[j].start <= temp.start&&i<j) j--;
        while (a[i].start >= temp.start&&i<j) i++;
        if (i<j)
        {
            struct time t = a[i];
            a[i]= a[j];
            a[j] = t;
        }
    }
    a[l] = a[i];
    a[i] = temp;
    quicksort(l,i-1);
    quicksort(i+1,r);
    return;
}

int main(){
    int t;
    cin >> t;
    while(t-- > 0){
        for(int i = 0;i < 1002;i ++) flag[i] = 0;
        int n;
        int sum = 0;
        cin>>n;
        for(int i = 0;i < n;i ++){
            cin >> a[i].end; //deadline
        }
        for(int i = 0;i < n;i ++){
            cin >> a[i].start; //reduced score
        }
        // 扣分从多到少的科目排序
       	quicksort(0,n-1);
//        for(int i = 0;i < n;i ++) cout<<a[i].start<<' '<<a[i].end<<endl;
        //在deadline相同的情况下使用扣分从多到少的科目排序
        for(int i = 0;i < n;i ++){
            if (arrange_day(a[i].end)){
				sum += a[i].start;
//				cout<<a[i].end;
			}
        }
        printf("%d\n",sum);
    }
    return 0;
}
```

### 分析
贪心，重点是找对排序根据
