#include<stdio.h>

int is_palindrome(char str[], int i, int j){
    while(i<j){
        if(str[i++]!=str[j--]) return 0;
    }
    return 1;
}

void longest_substring(char str[], int size){
    int longest = -1;
    int ans_s = -1;
    int ans_e = -1;

    for(int i=0;i<size;i++){
        for(int j=i;j<size;j++){
            if((j-i)>longest && is_palindrome(str, i, j)){
                ans_s = i;
                ans_e = j;
                longest = (j-i);
            }
        }
    }

    for(int i=ans_s;i<=ans_e;i++){
        printf("%c", str[i]);
    }

    return;
}

int str_len(char str[]){
    char *ptr = str;
    int length =0;
    while(*ptr!='\0'){
        length++;
        ptr++;
    }
    return length;
}

int main(){
    char str[100];
    scanf("%s", str);
    int size = str_len(str);

    longest_substring(str, size);
    return 0;
}