#include<stdio.h>
#include<math.h>
int min(int a,int b){
    return (a>b)?b:a;
}
int main(){
    int n,k;
    int a[21][11];
    int dp[21][11];
    while(scanf("%d %d",&n,&k)==2){
        for(int i = 0;i < n;i ++){
            for(int j = 0;j < k;j ++){
                scanf("%d",&a[i][j]);
                dp[i][j] = 99999999;
            }
        }
        for(int i = 0;i<k;i++){
            dp[n-1][i] = 0;
        }
        for(int i = n-2;i>=0;i--){
            for(int j = 0;j<k;j++){
                for(int l = 0;l<k;l++){
                    dp[i][j] = min(dp[i][j],dp[i+1][j]+abs(a[i][j]-a[i+1][l]));//注意细节
                }
            }
        }
        int min1 = dp[0][0];
        for(int i = 0;i<k;i++){
            if(dp[0][i]<min1) min1 = dp[0][i];
        }
        printf("%d\n",min1);
    }

    return 0;
}
