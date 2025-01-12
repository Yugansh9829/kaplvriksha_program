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

    int freq[26] = {0};

    for(int index=0;index<size_s;index++){
        freq[s[index]-'a']++;
    }

    for(int index=0;index<size_t;index++){
        if(freq[t[index]-'a']==0){
            printf("false");
            return;
        }else{
            freq[t[index]-'a']--;
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