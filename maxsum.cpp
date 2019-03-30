#include<stdio.h>
int max2(int a,int b){
	return a>b?a:b;
}

int main(){
    int n;
    scanf("%d",&n);
    int j = 1;
    while(j<=n){
        long max;
        long ans;
        int t;
        int start,end,start1,end1;
        scanf("%d",&t);
        scanf("%d",&ans);
        max = ans;
        start=start1 = 1;
        end=end1 = 1;
        for(int i = 2;i<=t;i++ ){
            int a;
            scanf("%d",&a);
            if(a>ans+a){
                start = i;
                end = i;
                ans = a;
            }else{
                ans += a;
                end = i;
            }
            if (ans>max){
                max = ans;
                start1 = start;
                end1 = end;
            }
        }



        printf("Case %d:\n",j);
        printf("%d %d %d\n",max,start1,end1);
        if(j<n){
            printf("\n");
        }
        j++;
    }


    return 0;
}
