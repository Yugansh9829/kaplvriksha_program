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

    int freq[26]={0};

    while(*s!='\0'){
        freq[*s-'a']++;
        s++;
    }

    for(int index=0;index<size_t;index++){
       if(freq[t[index]-'a']==0){
            return 0;
       }else{
        freq[t[index]-'a']--;
       }
    }

    return 1;
}

void find_and_group_anagram(int counter){
    int visited[counter];

    for(int index=0;index<counter;index++) visited[index] =0;

    printf("[");
    for(int index=0;index<counter;index++){
        if(visited[index])continue;

        if(index!=0) printf(",[\"%s\"", arr[index]);
        else printf("[\"%s\"", arr[index]);

        visited[index] = 1;

        for(int index_=index+1; index_<counter; index_++){

            if(!visited[index_] && is_anagram(arr[index], arr[index_] )){
                printf(",\"%s\"", arr[index_]);
                visited[index_] = 1;
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
