#include<stdio.h>
int max2(int a,int b){
	return a>b?a:b;
}

int main(){
    int n;
    int a[1001];
    int ans[1001];
    while(scanf("%d",&n)==1){
        int mmax = 0;
        if (n==0) break;
        for(int i = 0;i < n;i++){
            scanf("%d",&a[i]);
            ans[i] = a[i];
            int max = 0;
            for(int j = i-1;j--;j>=0){
                if(a[j]<a[i]){
                    max = max2(max,ans[j]);
                }
            }
            ans[i] += max;
            mmax = max2(mmax,ans[i]);
        }
        printf("%d\n",mmax);
    }


    return 0;
}
