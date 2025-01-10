// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int rows;
int cols;

void print_matrix(char *matrix[rows][cols]){
    // printf("reached\n");
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%s ", matrix[i][j]);
        }
        printf("\n");
    }
}

void check_vowels(char *matrix[rows][cols]){
    // printf("reached");
    int number_of_strings_with_vowels =0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            char *str = matrix[i][j];
            int idx = 0;
            // printf("comparing %c \n", *str);
            if(*(str)=='a' || *(str)=='e' || *(str)=='i' || *(str)=='o' || *(str)=='u' || *(str)=='A' || *(str)=='E' || *(str)=='I' || *(str)=='O' || *(str)=='U')
                number_of_strings_with_vowels++;
            
        }
    }
    
    printf("number of strings starting with a vowel are : %d\n", number_of_strings_with_vowels);
}

int find_length(char *str){
    char *iterator = str;
    int length=0;
    while(*iterator!='\0'){
        length++;
        iterator++;
    }
    return length;
}

void longest_name(char *matrix[rows][cols]){
    char *longest_words[100];
    int counter =0;
    int longest_length =-1;
    
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            int length = find_length(matrix[i][j]);
            
            if(length > longest_length){
                
                longest_length = length;
                counter =0;
                longest_words[counter++] = matrix[i][j];
                
                // printf("found longest word : %s\n", longest_words[counter-1]);

            }
            else if(length ==  longest_length){
                longest_words[counter++] = matrix[i][j];
            }
        }
    }
    
    printf("Longest names are : ");
    for(int i=0;i<counter;i++){
        printf("%s  ", longest_words[i]);
    }
    
    return;
}

int main() {
  
    int number_of_rows, number_of_cols;
    
    printf("enter number of rows : ");
    scanf("%d", &number_of_rows);
    printf("enter number of columns : ");
    scanf("%d", &number_of_cols);
    
    char *matrix[number_of_rows][number_of_cols];
    rows = number_of_rows;
    cols = number_of_cols;
    fflush(stdin);
    for(int i=0;i<number_of_rows;i++){
        for(int j=0;j<number_of_cols;j++){
            char *name = (char *)malloc(100 *sizeof(char));
            printf("Name at (%d, %d) : ", i,j);
            scanf("%s", name);
            matrix[i][j] = name;
        }
    }
    
    print_matrix(matrix);
    check_vowels(matrix);
    longest_name(matrix);
    
    return 0;
}
