#include<stdio.h>
#include<stdlib.h>
#include<string.h>

char *arr[100];

int is_anagram(char *s, char *t){
    int size_s = strlen(s);
    int size_t = strlen(t);
    if(size_s!=size_t){
        return 0;
    }

    int freq_s[26]={0};
    int freq_t[26]={0};

    while(*s!='\0'){
        freq_s[*s-'a']++;
        freq_t[*t-'a']++;
        s++;
        t++;
    }

    for(int i=0;i<26;i++){
        if(freq_s[i]!=freq_t[i])return 0;
    }

    return 1;
}

void find_and_group_anagram(int counter){
    int visited[counter];

    for(int i=0;i<counter;i++) visited[i] =0;

    printf("[");
    for(int i=0;i<counter;i++){
        if(visited[i])continue;

        if(i!=0) printf(",[\"%s\"", arr[i]);
        else printf("[\"%s\"", arr[i]);

        visited[i] = 1;

        for(int j=i+1;j<counter;j++){

            if(!visited[j] && is_anagram(arr[i], arr[j] )){
                printf(",\"%s\"", arr[j]);
                visited[j] = 1;
            }
        }
        printf("]");
    }
    printf("]");

}


int main(){
    char *str = (char *)malloc(100*sizeof(char));

    scanf("%s", str);

   
    int counter =0;
    while(*str != '\0'){

        if(*str >= 'a' && *str<='z'){
            char *word = (char *)malloc(100*sizeof(char));
            int idx =0;
            while(*str >= 'a' && *str<='z'){
                *(word+idx) = *str;
                str++;
                idx++;
            }
            str--;
            *(word+idx)='\0';
            arr[counter++] = word;
        }
        str++;
    }
    if(counter==0){
        printf("[[\"\"]]");
        return 0;
    }
    find_and_group_anagram(counter);




    return 0;
}