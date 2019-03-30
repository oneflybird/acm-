#include<stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    while(t-- >0){
        int m;
        int map[100][100];
        scanf("%d",&m);
        int i = 1;
        for(int i = 0;i < m;i ++){
            for(int j = 0;j <= i;j ++){
                scanf("%d",&map[i][j]);
            }
        }
        for(int i = m-2;i>=0;i--){
            for (int j = 0;j <= i;j ++){
                map[i][j] = (map[i+1][j]+map[i][j])>(map[i+1][j+1]+map[i][j])?(map[i+1][j]+map[i][j]):(map[i+1][j+1]+map[i][j]);
            }
        }
        // for(int i = 0;i < m;i ++){
        //     for(int j = 0;j <= i;j ++){
        //         printf("%d ",map[i][j]);
        //     }
        //     printf("\n");
        // }
        printf("%d\n",map[0][0]);
    }

    return 0;
}
