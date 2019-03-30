#include<stdio.h>
int max3(int a,int b,int c){
    int temp = a>b?a:b;
    return temp>c?temp:c;
}
int max2(int a,int b){
	return a>b?a:b;
}

int main(){
    int n;
    while(scanf("%d",&n) == 1){
        if(n==0) break;
        int map[100][11]={0};
        int x,y;
        int maxt = 0;
        for(int i = 0;i < n;i ++){
            scanf("%d %d",&x,&y);
            map[y][x] += 1;
            if(maxt<y) maxt=y;
        }
//        for(int i = 1;i<=y;i++){
//            for (int j = 0;j <= 10;j ++){
//            	printf("%d ",map[i][j]);
//            }
//            printf("\n");
//        }
        for(int i = maxt-1;i>=0;i--){
            for (int j = 0;j <= 10;j ++){
            	if(j==0){
            		map[i][j] = max2(map[i][j]+map[i+1][j],map[i][j]+map[i+1][j+1]);
				}else if(j==10){
					map[i][j] = max2(map[i][j]+map[i+1][j],map[i][j]+map[i+1][j-1]);
				}else{
                	map[i][j] = max3(map[i][j]+map[i+1][j],map[i][j]+map[i+1][j-1],map[i][j]+map[i+1][j+1]);

				}
            }
        }
        printf("%d\n",map[0][5]);
    }
    return 0;
}
