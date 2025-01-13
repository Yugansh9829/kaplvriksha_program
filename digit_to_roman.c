#include<stdio.h>
#include<stdlib.h>

void digit_to_number(int number){
    int values[] = {1, 4, 5, 9,10, 40, 50, 90, 100, 400, 500, 900, 1000};

    char *values_[13] = {"I", "IV", "V","IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
    char **ans = (char **)malloc(50*sizeof(char));
    
    for(int i=0;i<50;i++){
        ans[i] = (char *)malloc(2*sizeof(char));
    }

    int idx = 0;
    int i=12;
        while(number>0){
            int count = number/values[i];
            number = number%values[i];
            while(count--){
                ans[idx++] = values_[i];
            }
            i--;
        }

    for(int i=0;i<idx;i++) printf("%s", ans[i]);

    free(ans);
    return;
}

int main(){
    int number;

    scanf("%d", &number);

    digit_to_number(number);

    return 0;
}