Tian Ji -- The Horse Racing
Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)
Total Submission(s) : 57   Accepted Submission(s) : 26
Problem Description
Here is a famous story in Chinese history.

"That was about 2300 years ago. General Tian Ji was a high official in the country Qi. He likes to play horse racing with the king and others."

"Both of Tian and the king have three horses in different classes, namely, regular, plus, and super. The rule is to have three rounds in a match; each of the horses must be used in one round. The winner of a single round takes two hundred silver dollars from the loser."

"Being the most powerful man in the country, the king has so nice horses that in each class his horse is better than Tian's. As a result, each time the king takes six hundred silver dollars from Tian."

"Tian Ji was not happy about that, until he met Sun Bin, one of the most famous generals in Chinese history. Using a little trick due to Sun, Tian Ji brought home two hundred silver dollars and such a grace in the next match."

"It was a rather simple trick. Using his regular class horse race against the super class from the king, they will certainly lose that round. But then his plus beat the king's regular, and his super beat the king's plus. What a simple trick. And how do you think of Tian Ji, the high ranked official in China?"



Were Tian Ji lives in nowadays, he will certainly laugh at himself. Even more, were he sitting in the ACM contest right now, he may discover that the horse racing problem can be simply viewed as finding the maximum matching in a bipartite graph. Draw Tian's horses on one side, and the king's horses on the other. Whenever one of Tian's horses can beat one from the king, we draw an edge between them, meaning we wish to establish this pair. Then, the problem of winning as many rounds as possible is just to find the maximum matching in this graph. If there are ties, the problem becomes more complicated, he needs to assign weights 0, 1, or -1 to all the possible edges, and find a maximum weighted perfect matching...

However, the horse racing problem is a very special case of bipartite matching. The graph is decided by the speed of the horses --- a vertex of higher speed always beat a vertex of lower speed. In this case, the weighted bipartite matching algorithm is a too advanced tool to deal with the problem.

In this problem, you are asked to write a program to solve this special case of matching problem.


Input
The input consists of up to 50 test cases. Each case starts with a positive integer n (n <= 1000) on the first line, which is the number of horses on each side. The next n integers on the second line are the speeds of Tian’s horses. Then the next n integers on the third line are the speeds of the king’s horses. The input ends with a line that has a single 0 after the last test case.


Output
For each input case, output a line containing a single number, which is the maximum money Tian Ji will get, in silver dollars.


Sample Input
3
92 83 71
95 87 74
2
20 20
20 20
2
20 19
22 18
0


Sample Output
200
0
0

```c++
#include<cstdio>
#include<iostream>
using namespace std;
//普通快排
void quicksort(int *a,int l,int r){
	int temp = a[l];
	int i=l;
  int j=r;
	if(i>j){
		return;
	}
	while (i<j)
    {
      while (a[j]>=temp&&i<j) j--;
      while (a[i]<=temp&&i<j) i++;
        if (i<j)
        {
            int t = a[i];
            a[i]= a[j];
            a[j] = t;
        }
    }
    a[l] = a[i];
    a[i] = temp;
    quicksort(a,l,i-1);
    quicksort(a,i+1,r);
    return;
}
int main(){
  int n;
  int a[1001];
  int b[1001];
  while(scanf("%d",&n) == 1){
	if(n==0) break;
    for(int i = 0;i < n;i ++)
    	cin>>a[i];
    for(int i = 0;i < n;i ++)
      	cin>>b[i];
    quicksort(a,0,n-1);
    quicksort(b,0,n-1);
//    for(int i = 0;i<n;i++)
//    	printf("%d",a[i])
    int af = 0;
	int bf = 0;
	int al = n-1;
	int bl = n-1;
    int sum = 0;
    while(af<n && al >= af && bl >= bf){
	//a的下等马和b的下等马比较，如果大就直接比赛
		if(a[al] == b[bf] && a[af] == b[bl]) break;
    	while(a[af] > b[bf] && al >= 0 && af < n && al >= af && bl >= bf){
        	sum += 200;
			af ++;
			bf ++;
      	}
      	while(a[al] > b[bl] && al >= 0 && af < n && al >= af && bl >= bf){
        	sum += 200;
			al --;
			bl --;
      	}
		if(af<n && al>=0 && al >= af){
			if(a[af]<b[bl])
				sum -= 200;
			bl --;
			af ++;
		}
	}
    printf("%d\n",sum);
}
  return 0;
}
```
### 分析
一开始把贪心想的过于简单，思路只是从小到大排序后 进行比较，多余的减两百。但这种思路其实并没有贪心。贪心的前提是局部最大化，且**必须局部最大化**，而一开始的思路并没有让田忌的马效益最大化，所以思路应该是如何让田忌的马达到最大化（最弱的马消耗最强的马），除此之外，还应该严格判断比较停止的条件。
