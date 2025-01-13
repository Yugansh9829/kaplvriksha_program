#include<stdio.h>
#include<stdlib.h>


void generate(int numRows) {

    int **arr = (int **)malloc(numRows*sizeof(int*));
    for(int i=0;i<numRows;i++){
        arr[i] = (int *)malloc((i+1)*sizeof(int));
    }

    for(int i=0;i<numRows;i++){
        arr[i][0] =1;
        arr[i][i] = 1;
        if(i>=2){
            for(int j=1;j<i;j++){
                arr[i][j] = arr[i-1][j-1]+arr[i-1][j];
            }
        }
    }

    for(int i=0;i<numRows;i++){
        for(int j=0;j<=i;j++){
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    return ;

}


int main(){
    int rows;
    scanf("%d", &rows);

    generate(rows);

    return 0;
}