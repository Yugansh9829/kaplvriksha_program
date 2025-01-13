#include<stdio.h>

int calculate_size(char string[]){
    char *pointer = string;
    int length = 0;
    while(*pointer != '\0'){
        pointer++;
        length++;
    }
    return length;
}

int atoi(char string[], int size_of_string){
    int number = 0;
    char *pointer = string;
    int negative = 0;
    if(*pointer == '-'){
        negative = 1;
        pointer++;
    }
    while(*pointer != '\0'){

        if(*pointer-'0'<0 || *pointer-'0'>9) return 0;

        number = (number*10) + (*(pointer)-'0');
        pointer++;
    }

    if(negative) number = -number;

    return number;
}

int main(){

    char input_string[100];
    scanf("%s", input_string);

    int size = calculate_size(input_string);
    int ans = atoi(input_string, size);

    printf("number is %d", ans);

    return 0;
}
