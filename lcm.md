# lcm

> 来源 ：杭电oj

## Least Common Multiple

##### Time Limit : 2000/1000ms (Java/Other)   Memory Limit : 65536/32768K (Java/Other)

##### Total Submission(s) : 134   Accepted Submission(s) : 48

Problem Description

The least common multiple (LCM) of a set of positive integers is the smallest positive integer which is divisible by all the numbers in the set. For example, the LCM of 5, 7 and 15 is 105.

Input

Input will consist of multiple problem instances. The first line of the input will contain a single integer indicating the number of problem instances. Each instance will consist of a single line of the form m n1 n2 n3 ... nm where m is the number of integers in the set and n1 ... nm are the integers. All integers will be positive and lie within the range of a 32-bit integer.<br>

 

Output

For each problem instance, output a single line containing the corresponding LCM. All results will lie in the range of a 32-bit integer.<br>

 

Sample Input

```
2
3 5 7 15
6 4 10296 936 1287 792 1
```

 

Sample Output

```
105
10296
```

 

Source

East Central North America 2003, Practice



## 代码如下

```c++
#include<cstdio>
#include<iostream>
using namespace std;
//更相减法 
int gcd(int a, int b){
	if(b == a){
		return a;
	}else if(a > b){
		return gcd(b, a-b);
	}else if(a < b){
		return gcd(a, b-a);
	}
}
int main(){ 
	int a,b,n,r,m;
	scanf("%d",&n);
	while(n-->0){
		scanf("%d",&m);
		int n = 1;
		if(m==n){
			cin>>a;
			cout<<a<<endl;
			continue;
		}
		while(n<m){
			if(n==1){
				scanf("%d %d",&a,&b);
			}else{
				cin>>b;
			}
			r = gcd(a,b);
			a = a/r*b;
			n++;
		}
		printf("%d\n",a);
	}
	
	
	
	return 0;
} 
```