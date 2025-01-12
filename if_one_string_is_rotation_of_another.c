#include<stdio.h>

int calculate_size(char string[]){
    char *pointer = string;
    int length = 0;

    while(*pointer!='\0'){
        pointer++;
        length++;
    }

    return length;
}

int found_string(char string_first[], char string_second[], int start_pointer, int end_pointer){
    int index = 0;
    for(int i= start_pointer;i<=end_pointer;i++){
        if(string_first[i]!=string_second[index++]){
            return 0;
        }
    }
    return 1;
}

void if_first_string_is_rotation_of_second(char string_first[], char string_second[], int size1, int size2){

    for(int i=0;i<(size1);i++){
        string_first[size1+i] = string_first[i];
    }

    int start_pointer = 0;
    int end_pointer = size2-1;

    while(end_pointer<(size1+size2)){

        if(found_string(string_first, string_second, start_pointer, end_pointer)){
            printf("True");
            return;
        }
        start_pointer++;end_pointer++; 
    }

    printf("false");
    return; 
}

int main(){
    char string_first[200];
    char string_second[100];

    scanf("%[^\n]s", string_first);
    fflush(stdin);
    scanf("%[^\n]s", string_second);

    int size1 = calculate_size(string_first);
    int size2 = calculate_size(string_second);

    if_first_string_is_rotation_of_second(string_first, string_second, size1, size2);

}