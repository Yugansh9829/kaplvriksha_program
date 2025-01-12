#include<stdio.h>
int calculate_size(char string[]){
    char *pointer = string;
    int length = 0;

    while(*pointer!='\0'){
        length++;
        pointer++;
    }

    return length;
}

void find_longest_word_in_string(char string[], int size){
    int pointer = 0;
    int longest_word_length = 0;
    int length = 0;

    while(pointer<size){
        while(string[pointer]==' '&& pointer<size)pointer++;
        if(pointer>=size)break;

        while(string[pointer]!=' '&& pointer<size){
            length++;
            pointer++;
        }

        if(length>longest_word_length) longest_word_length = length;
        length = 0;
    }

    printf("longest word length is %d", longest_word_length);

    return;
}

int main(){
    char string[100];
    scanf("%[^\n]s", string);
    int size = calculate_size(string);
    find_longest_word_in_string(string, size);
    return 0;   
}