#include<stdio.h>
#include<string.h>
#include<stdlib.h>


void find_longest_word(char str[], int size){
    int sp = 0;
    int ep = 0;
    int max_len = 0;

    for(int i=0;i<size;i++){
        while(i<size && str[i]==' ')i++;
        if(i>=size)break;
        sp = i;
        while(i<size && str[i]!=' ')i++;

        if(max_len<(i-sp)){
            ep = sp;
            max_len = (i-sp);
        }
    }
    for(int i=ep;i<=(ep+max_len);i++) printf("%c", str[i]);
        
}

int main(){

    char str[100];
    scanf("%[^\n]s", str);

    int size = strlen(str);
    find_longest_word(str, size);
}