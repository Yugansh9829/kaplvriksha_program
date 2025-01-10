#include<stdio.h>

int calculate_size(char s[100]){
    char *ptr = s;
    int length =0;
    while(*ptr!='\0'){
        length++;
        ptr++;
    }
    return length;
}

void find_anagram(char s[100], char t[100]){
    int size_s = calculate_size(s);
    int size_t = calculate_size(t);

    if(size_s!=size_t){
        printf("false");
        return;
    }

    int freq_1[26] = {0};
    int freq_2[26] = {0};

    for(int i=0;i<size_s;i++){
        freq_1[s[i]-'a']++;
        freq_2[t[i]-'a']++;
    }

    for(int i=0;i<26;i++){
        if(freq_1[i]!=freq_2[i]){
            printf("false");
            return;
        }
    }

    printf("true");
    return ;

}


int main(){

    char s[100];
    char t[100];

    scanf("%s", s);
    scanf("%s", t);
    
    find_anagram(s, t);

    return 0;
}