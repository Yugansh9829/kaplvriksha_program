#include<stdio.h>

int cal_size(char str[]){
    char *ptr = str;
    int length = 0;
    while(*ptr!='\0'){
        ptr++;
        length++;
    }

    return length;
}

void remove_character(char str[], char r, int size){
    char *ptr = str;
    int idx =0;

    for(int i=0;i<size;i++){
        if(str[i]!=r)str[idx++] = str[i];
    }
    str[idx]='\0';
    printf("%s", ptr);
}

int main(){

    char str[100];
    scanf("%[^\n]s", str);
    fflush(stdin);
    char a;
    scanf("%c", &a);

    int size = cal_size(str);

    remove_character(str, a, size);


    return 0;
}