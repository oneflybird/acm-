#include <stdio.h>
#include<string.h>
int min(int a,int b){return a>b?b:a;}

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

int dp[2001][1001];
int main(){
    int n,k;
    int a[2001];
    while(scanf("%d %d",&n,&k)==2){
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    quicksort(a,1,n);//从小到大排序
        for(int i = 0; i <= n; i++)
        {
            for(int j = 0; j <= k; j++)
                dp[i][j] = 0x3fffffff;
            dp[i][0] = 0;
}
    for(int i = 2;i<=n;i++){
        for(int j = 1;j*2 <= i&&j<=k;j ++ ){
            dp[i][j] = min(dp[i-1][j],dp[i-2][j-1]+(a[i]-a[i-1])*(a[i]-a[i-1]));
        }
    }
    printf("%d\n",dp[n][k]);
}
    return 0;
}
