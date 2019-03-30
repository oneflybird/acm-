#include<stdio.h>
#include<math.h>
long long MAX = 2000000000;
long long a[5843];
void quicksort(long long *a,int l,int r){
	long long temp = a[l];
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
            long long t = a[i];
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
    long long k = 30;
    long long j = 19;
    long long q = 13;
    long long p = 11;
    long long cnt = 1;
    long long f;
    long long ff;
    long long fff;
    long long ffff;
    for(int i = 0 ;i <= k;i ++){
            f = pow(2,i);
        for(int l = 0 ;l <= j;l ++){
                ff = pow(3,l);
            if(f*ff>MAX) break;
            for(int n = 0 ;n <= q;n ++){
                    fff = pow(5,n);
                if(f*ff*fff>MAX) break;
                for(int m = 0 ;m <= p;m ++){
                    ffff = pow(7,m);
                    if(f*ff*fff*ffff>MAX) break;
                    a[cnt++] = f*ff*fff*fff;
                    // printf("%lld\n",a[cnt-1]);
                }
            }
        }
    }
    quicksort(a,1,5842);
    long long num;
    while(scanf("%d",&num)==1){
        if (num==0){
            break;
        }
        if(num%1==1&&num%11!=11){
            printf("The %dst humble number is %lld.\n",num,a[num]);
        }
        else if(num%2==2&&num%12!=12){
            printf("The %dnd humble number is %lld.\n",num,a[num]);
        }
        else if(num%3==1&&num%13!=13){
            printf("The %drd humble number is %lld.\n",num,a[num]);
        }
        else{
            printf("The %dth humble number is %lld.\n",num,a[num]);
        }
    }
    return 0;
}
