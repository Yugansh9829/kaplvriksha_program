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

int string_found_in_window(char string_first[], char string_second[], int start_pointer, int end_pointer){
    int index = 0;

    for(int itr = start_pointer; itr<=end_pointer; itr++){
        if(string_first[itr]!=string_second[index++]){
            return 0;
        }
    }
    return 1;
}

void string_exists_in_another_string(char string_first[], char string_second[], int size1, int size2){
    int start_pointer = 0;
    int end_pointer =( size2-1);

    while(end_pointer<size1){
        if(string_found_in_window(string_first, string_second,start_pointer, end_pointer)){
            printf("founded string second in string first at index : %d", start_pointer);
            return;
        }
        start_pointer++;
        end_pointer++;
    }

    printf("-1\n");
    return;
}

int main(){

    char first_input_string[100];
    char second_input_string[100];

    scanf("%[^\n]", first_input_string);
    fflush(stdin);
    scanf("%[^\n]", second_input_string);

    int size_of_first_string = calculate_size(first_input_string);
    int size_of_second_string = calculate_size(second_input_string);

    //we are checking that second input string exists in first input string or not.
    string_exists_in_another_string(first_input_string, second_input_string, size_of_first_string, size_of_second_string);

}