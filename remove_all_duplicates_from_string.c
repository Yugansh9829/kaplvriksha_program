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

void remove_all_duplicate_characters_from_string(char string[], int size_of_string){
    int visited_array[26] = {0};
    
    for(int i=0;i<size_of_string;i++){
       if(visited_array[string[i]-'a']==0){
            printf("%c", string[i]);
            visited_array[string[i]-'a']=1;
       }
    }

    return;
}

int main(){

    char input_string[100];
    scanf("%s", input_string);
    int size_of_string = calculate_size(input_string);

    remove_all_duplicate_characters_from_string(input_string, size_of_string);

}