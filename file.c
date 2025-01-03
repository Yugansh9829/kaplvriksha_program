#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int find_length(char *word){
    int length = 0;
    char *itr = word;
    while(*itr!='\0'){
        length++;
        itr++;
    }
    return length;
}

void find_word_index(char *str, int size){
    char *start_word_pointer = str;
    char *end_word_pointer = str;

    char *pointer_to_end = str + (size-1);
    int ans =0;

    while(end_word_pointer <= pointer_to_end){

        while(*end_word_pointer==' ' && end_word_pointer <= pointer_to_end){
            end_word_pointer++;
        }

        start_word_pointer = end_word_pointer;
        while(*end_word_pointer!= ' ' && end_word_pointer <= pointer_to_end) end_word_pointer++;
        *end_word_pointer = '\0';

        char *word = start_word_pointer;
        int size_ = find_length(word);

        if(size_ > ans) ans = size_;

        end_word_pointer++;
    }

    printf("%d", ans);

    return;
}

int main(){

    char *str = (char *)malloc(100*sizeof(char*));

    scanf("%[^\n]s", str);

    int size = strlen(str);

    // printf("size is : %d \n", size);
    find_word_index(str, size);


    return 0;
}