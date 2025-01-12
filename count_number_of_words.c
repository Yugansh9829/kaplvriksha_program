#include<stdio.h>

int calculate_size(char string[]){
    int length =0;
    char *pointer = string;
    
    while(*pointer!='\0'){
        pointer++;
        length++;
    }
    
    return length;
}

void count_number_of_words_in_string(char string[], int size){
    int number_of_words = 0;

    int pointer =0;

    while(pointer<size){
        while(string[pointer]==' ' && pointer<size)pointer++;

        if(pointer>=size) break;

        number_of_words+=1;

        while(string[pointer]!=' '&& pointer<size)pointer++;
    }

    printf("Number of words in strings are : %d", number_of_words);

    return;
}

int main(){
    char input_string[100];
    scanf("%[^\n]s", input_string);
    int size_of_string = calculate_size(input_string);

    count_number_of_words_in_string(input_string, size_of_string);

}