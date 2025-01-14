#include<stdio.h>
#include<math.h>

int calculate_size(char str[]){
    char *ptr = str;
    int length = 0;
    while(*ptr!='\0'){
        length++;
        ptr++;
    }
    return length;
}

void calculate_answer(char str[], int size){
    int ans = 1;
    int power = 0;
    for(int i=size-1;i>=0;i--){
        ans+= (str[i]-'A'+1)*(pow(26,power++));
    }

    printf("%d", ans);
}

int main(){

    char str[100];
    scanf("%s", str);
    int size = calculate_size(str);

    calculate_answer(str, size);
    
}