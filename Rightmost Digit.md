# Rightmost Digit

##### Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)

##### Total Submission(s) : 104   Accepted Submission(s) : 41

Problem Description

Given a positive integer N, you should output the most right digit of N^N.<br>

 

Input

The input contains several test cases. The first line of the input is a single integer T which is the number of test cases. T test cases follow.<br>Each test case contains a single positive integer N(1<=N<=1,000,000,000).<br>

 

Output

For each test case, you should output the rightmost digit of N^N.<br>

 

Sample Input

```
2
3
4
```

 

Sample Output

```
7
6

<div style='font-family:Times New Roman;font-size:14px;background-color:F4FBFF;border:#B7CBFF 1px dashed;padding:6px'><div style='font-family:Arial;font-weight:bold;color:#7CA9ED;border-bottom:#B7CBFF 1px dashed'><i>Hint</i></div>
In the first case, 3 * 3 * 3 = 27, so the rightmost digit is 7.
In the second case, 4 * 4 * 4 * 4 = 256, so the rightmost digit is 6.
</div>
```

 

Author

Ignatius.L

 ## 题解

```c++
#include<cstdio>
#include<iostream>
using namespace std;
int main(){
	int n;
	long long a;
	long long sum;
	long long cnt;
	cin>>n;
	while(n-->0){
		cin>>a;
		cnt = a;
		sum = 1;
		while(cnt != 0){
			a %= 10;
			if(cnt&1){    //如果cnt为奇数 
				sum *= a; 
				sum %= 10;
			}
				a *= a;
				cnt >>= 1;
		}
		printf("%lld\n",sum);
	}
	 
	return 0;
} 
```

