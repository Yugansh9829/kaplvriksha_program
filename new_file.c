#include<stdio.h>

void print_pattern(int n){

    for(int i=1;i<=n;i++){

        for(int number=1;number<=i;number++){
            printf("%d", number);
        }

        for(int spaces=(2*(n-i));spaces>0;spaces--) printf(" ");

        for(int back_num=i;back_num>=1;back_num--) printf("%d", back_num);

        printf("\n");
    }

    for(int i=n-1;i>=0;i--){

        for(int number=1;number<=i;number++){
            printf("%d", number);
        }

        for(int spaces=(2*(n-i));spaces>0;spaces--) printf(" ");

        for(int back_num=i;back_num>=1;back_num--) printf("%d", back_num);

        printf("\n");
    }
}


int main(){

    int rows;
    scanf("%d",&rows);
    print_pattern(rows);
    
    return 0;
}